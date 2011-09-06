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

int main()
{
    //freopen("wedstrijd.input", "r", stdin);

    int ncases;
    cin >> ncases;
    cin.ignore();
    while (ncases--) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        int m, coin;
        vector<int> coins;
        ss >> m;
        while (ss >> coin)
            coins.pb(coin);

        int ways[m+1];
        memset(ways, 0, sizeof(ways));
        ways[0] = 1;

        for (int j = 0; j < sz(coins); ++j)
            for (int i = 1; i <= m; ++i)
                if (i - coins[j] >= 0)
                    ways[i] += ways[i-coins[j]];

        cout << ways[m] << endl;
    }

    return 0;
}
