// includes {{{
#include <algorithm> //min, max, swap, find, ...
#include <bitset> //memory efficient array van bools
#include <cassert> //assert statement
#include <cctype> //isalnum, isalpha, isdigit, tolower, ..
#include <climits> //INT_MAX, UINT_MAX, ..
#include <cmath> //sin, asin, exp, log10, pow, floor, ceil, ..
#include <cstdio> //freopen, printf, scanf, ..
#include <cstdlib> //abs, atoi, malloc, free, ..
#include <cstring> //functies voor c strings, memset, ..
#include <deque> //double ended queue
#include <functional> //aantal functies voor operators
#include <iomanip> //setw, dec, hex, left, right, ..
#include <iostream> //cin, cout, ..
#include <iterator> //verschillende inserters
#include <list> //double linked list
#include <map> //key-value container met O(logn) operaties
#include <numeric> //accumulate, inner product, partialsum, ..
#include <queue> //first in-first out
#include <set> //container met unieke elementen
#include <sstream> //istringstream, ostringstream, ..
#include <stack> //first in-last out
#include <utility> //pair, make_pair
#include <vector> //dynamisch groeiende array
using namespace std;
// }}}
// defines {{{
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define all(c) (c).begin(),(c).end()
#define foreach(c,i) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
// }}}

#define MAX 10

int sz;
int a[MAX + 2][MAX + 2];
int toplace;
int letters[MAX*MAX];
int placed[MAX*MAX];

vector< pair<int, int> > pos;
bool this1, this2, this4, this8;
bool other1, other2, other4, other8, bad;

int notplaceable(int piece, int r, int c)
{
    this1 = piece & 1;
    other4 = a[r - 1][c] == -1 ? this1 : a[r - 1][c] & 4;
    if (this1 ^ other4)
        return 1;

    this2 = piece & 2;
    other8 = a[r][c + 1] == -1 ? this2 : a[r][c + 1] & 8;
    if (this2 ^ other8)
        return 1;

    this4 = piece & 4;
    other1 = a[r + 1][c] == -1 ? this4 : a[r + 1][c] & 1;
    if (this4 ^ other1)
        return 1;

    this8 = piece & 8;
    other2 = a[r][c - 1] == -1 ? this8 : a[r][c - 1] & 2;
    if (this8 ^ other2)
        return 1;

    return 0;
}

int place(int placed_num, int p)
{
    if (placed_num == toplace)
        return 1;

    int r = pos[p].first;
    int c = pos[p].second;

    for (int i = 0; i < toplace; ++i) {
        int val = letters[i];
        if (!placed[i] && !notplaceable(val, r + 1, c + 1)) {
            placed[i] = 1;
            a[r + 1][c + 1] = val;
            int ret = place(placed_num + 1, p + 1);
            if (ret) return 1;
            a[r + 1][c + 1] = -1;
            placed[i] = 0;
        }
    }
    return 0;
}

void one_run()
{
    //read
    string choice;
    cin >> sz >> choice;
    toplace = choice.size();

    for (int i = 0; i < toplace; ++i) {
        placed[i] = 0;
        letters[i] = choice[i] - 'A' + 1;
    }
    memset(a, 0, sizeof(a));
    pos.clear();
    for (int i = 0; i < sz; ++i) {
        string t;
        cin >> t;
        for (int j = 0; j < sz; ++j) {
            if (isalpha(t[j]))
                a[i + 1][j + 1] = t[j] - 'A' + 1;
            else {
                a[i + 1][j + 1] = -1;
                pos.push_back(make_pair(i, j));
            }
        }
    }

    //backtrack
    place(0, 0);

    //print
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j)
            cout << char(a[i + 1][j + 1] + 'A' - 1);
        cout << endl;
    }
}

int main()
{
    //freopen("pijp.in", "r", stdin);

    int N;
    cin >> N;
    while (N--) one_run();

    return 0;
}

