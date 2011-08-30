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

#define MAX 200

void compress(char *f, char *c)
{
    int i = 0, j = 0;
    while (f[i]) {
        char prev = f[i];
        int n = 0;
        while (f[i] == prev)
            ++n, ++i;
        while (n >= 4) {
            c[j++] = '-';
            c[j++] = min(n, 26) + 'A' - 1;
            c[j++] = prev;
            n -= 26;
        }
        while (n-- > 0)
            c[j++] = prev;
    }
    c[j] = 0;
}

void decompress(char *f, char *c)
{
    int i = 0, j = 0;
    while (c[j]) {
        if (c[j] == '-') {
            int n = c[++j] - 'A' + 1;
            int add = c[++j];
            while (n--)
                f[i++] = add;
            ++j;
        } else
            f[i++] = c[j++];
    }
    f[i] = 0;
}

int main()
{
    //freopen("wedstrijd.input", "r", stdin);

    int ncases;
    cin >> ncases;
    while (ncases--) {
        char full[MAX], comp[MAX];
        cin >> full >> comp;

        if (comp[0] == '?')
            compress(full, comp);
        else
            decompress(full, comp);

        cout << full << " " << comp << endl;
    }

    return 0;
}
