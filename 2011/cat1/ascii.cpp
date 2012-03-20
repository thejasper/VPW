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

typedef vector< string > vs;

pair<int, int> find_match(vs& big, vs& small)
{
    int m = sz(big), n = sz(big[0]);
    int mm = sz(small), nn = sz(small[0]);

    for (int i = 0; i < m - mm + 1; ++i) {
        for (int j = 0; j < n - nn + 1; ++j) {
            int same = 1;
            for (int r = 0; r < mm; ++r) {
                for (int c = 0; c < nn; ++c) {
                    if (small[r][c] != big[i + r][j + c]) {
                        same = 0;
                        break;
                    }
                }
                if (!same) break;
            }
            if (same) return mp(i + 1, j + 1);
        }
    }
    return mp(-1, -1);
}

vs rotate(vs& small)
{
    int m = sz(small), n = sz(small[0]);
    vector<string> ret(n, string(m, ' '));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ret[i][m - j - 1] = small[j][i];
        }
    }

    return ret;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    string t;
    cin >> n;
    while (n--) {
        int m, n;
        cin >> m >> n;
        vs big;
        for (int i = 0; i < m; ++i) {
            cin >> t;
            big.pb(t);
        }

        int cases;
        cin >> cases;
        while (cases--) {
            int mm, nn;
            cin >> mm >> nn;
            vs small;
            for (int i = 0; i < mm; ++i) {
                cin >> t;
                small.pb(t);
            }

            for (int i = 0; i < 360; i += 90) {
                pair<int, int> res;
                if ((res = find_match(big, small)) != mp(-1, -1)) {
                    cout << res.st << " " << res.nd << " " << i << endl;
                    break;
                }
                small = vs(rotate(small));
            }
        }
    }

    return 0;
}

