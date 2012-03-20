// includes {{{
#include <algorithm> //min, max, swap, find, ...
#include <bitset> //memory efficient array van bools
#include <cassert> //assert statement
#include <cctype> //isalnum, isalpha, isdigit, tolower, ..
#include <climits> //INT_MAX, UINT_MAX, ..
#include <cmath> //sin, asin, exp, log10, pow, floor, ceil, ..
#include <cstdio> //freopen, printf, scanf, ..
#include <cstdlib> //abs, atoi, malloc, free, ..
#include <cstring> //functies voor c strings, strlen, ..
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

int normalize(char c)
{
    return c - 'A' + 1;
}

string convert(string code, string s, int decode)
{
    int n = sz(code), m = sz(s);
    int i = 0;

    for (int j = 0; j < m; ++j) {
        char c;
        if (s[j] == ' ')
            c = 0;
        else
            c = normalize(s[j]);

        if (!decode)
            c = (c + normalize(code[i])) % 27;
        else
            c = (c - normalize(code[i]) + 27) % 27;

        s[j] = !c ? ' ' : c + 'A' - 1;
        if (++i == n) i = 0;
    }

    return s;
}

int main()
{
    freopen("input.txt", "r", stdin);

    for (int i = 0; i < 2; ++i) {
        int n;
        cin >> n;
        while (n--) {
            string code, s;
            cin >> code;
            cin.ignore();
            getline(cin, s);

            cout << convert(code, s, i) << endl;
        }
    }

    return 0;
}

