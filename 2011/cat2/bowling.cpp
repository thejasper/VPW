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

typedef vector<int> vi;

vi get_nums()
{
    vi res;
    string s;
    getline(cin, s);
    istringstream ss(s);

    int num;
    while (ss >> num)
        res.pb(num);
    return res;
}

vi get_results(vi& p)
{
    vi res;
    int i = 0;
    int n = sz(p);
    int score = 0;

    while (i < n && sz(res) != 10) {
        if (p[i] == 10) { //strike
            score += 10;
            if (i + 1 < n)
                score += p[i + 1];
            if (i + 2 < n)
                score += p[i + 2];
            ++i;
        } else if (i + 1 < n && p[i] + p[i + 1] == 10) { //spare
            score += 10;
            if (i + 2 < n)
                score += p[i + 2];
            i += 2;
        } else if (p[i] > 10 || (i + 1 < n && p[i] + p[i + 1] > 10)) { //fout
            res.clear();
            break;
        } else { //normaal
            score += p[i] + p[i + 1];
            i += 2;
        }
        res.pb(score);
    }

    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        vi a = get_nums();
        vi results = get_results(a);

        if (sz(results) != 10)
            cout << "ONGELDIG" << endl;
        else {
            for (int i = 0; i < 9; ++i)
                cout << results[i] << " ";
            cout << results[9] << endl;
        }
    }

    return 0;
}

