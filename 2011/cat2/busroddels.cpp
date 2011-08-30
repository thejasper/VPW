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
    while (ncases--) {
        int b;
        cin >> b;
        vector<int> h[b]; 
        for (int i = 0; i < b; ++i) {
            int aantal;
            cin >> aantal;
            for (int j = 0; j < aantal; ++j) {
                int halte;
                cin >> halte;
                h[i].pb(halte);
            }
        }

        int time = 0;
        int curr[b];
        int talked[b][b];
        memset(curr, 0, sizeof(curr));
        memset(talked, 0, sizeof(talked));

        for (int i = 0; i < b; ++i)
            talked[i][i] = 1;
        while (time <= 1440) {
            for (int i = 0; i < b; ++i) {
                for (int j = i + 1; j < b; ++j) {
                    if (h[i][curr[i]] == h[j][curr[j]]) {
                        for (int k = 0; k < b; ++k) {
                            talked[i][k] |= talked[j][k];
                            talked[j][k] |= talked[i][k];
                        }
                    }
                }
            }

            int check=1;
            for (int i = 0; i < b; ++i)
                for (int j = 0; j < b; ++j)
                    if (!talked[i][j])
                        check=0;
            if (check) break;

            for (int i = 0; i < b; ++i)
                curr[i] = (curr[i] + 1) % sz(h[i]);
            ++time;
        }

        if (time <= 1440)
            cout << time << endl;
        else
            cout << "NOOIT" << endl;
    }

    return 0;
}
