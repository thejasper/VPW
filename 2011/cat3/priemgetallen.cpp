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

#define MAX 33000

int isprime(int n)
{
    if (n == 2) return 1;
    if (n <= 1 || n % 2 == 0) return 0;
    for (int i = 3; i <= ceil(sqrt(n)); i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    //freopen("wedstrijd.input", "r", stdin);

    int prime[MAX];
    for (int i = 0; i < MAX; ++i)
        prime[i] = isprime(i);

    int ncases;
    cin >> ncases;
    while (ncases--) {
        int n, m;
        cin >> n >> m;

        vector<int> sum(1, 0);
        for (int i = n; i <= m; ++i)
            if (prime[i])
                sum.pb(sum.back() + i);

        int num = sz(sum);
        int streak[m+1];
        memset(streak, 0, sizeof(streak));
        for (int i = 0; i < num; ++i) {
            for (int j = i + 1; j < num; ++j) {
                int s = sum[j] - sum[i];
                if (s <= m && j - i > streak[s] && isprime(s))
                    streak[s] = j - i;
            }
        }

        cout << max_element(streak + n, streak + m + 1) - streak << endl;
    }

    return 0;
}
