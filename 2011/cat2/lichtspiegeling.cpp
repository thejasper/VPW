// includes {{{
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
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

int m, n;

int correct(string *a, int r, int c, int dr, int dc)
{
    char start = a[r][c];
    do {
        r += dr;
        c += dc;
        if (a[r][c] != ' ') {
            swap(dr, dc);
            if (a[r][c] == '/')
                dr = -dr, dc = -dc;
        }
    } while (r > 0 && r <= m && c > 0 && c <= n);

    return a[r][c] == start;
}

int check(string *a)
{
    for (int i = 1; i <= m; ++i)
        if (!correct(a, i, 0, 0, 1))
            return 0;
    for (int i = 1; i <= n; ++i)
        if (!correct(a, 0, i, 1, 0))
            return 0;
    return 1;
}

int main()
{
    freopen("wedstrijd.input", "r", stdin);

    int ncases;
    cin >> ncases;
    while (ncases--) {
        cin >> m >> n;
        cin.ignore();

        string a[m+2];
        for (int i = 0; i < m + 2; ++i)
            getline(cin, a[i]);

        cout << (check(a) ? "correct" : "verkeerd") << endl;
    }

    return 0;
}
