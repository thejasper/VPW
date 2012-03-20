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

struct stof {
    int num;
    char name;
};

bool shouldDelete(pair<int, pair<int, char> > p)
{
    return p.nd.st == 0;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int chance[12 + 1] = {0};
    for (int i = 1; i <= 6; ++i)
        for (int j = 1; j <= 6; ++j)
            ++chance[i + j];
    chance[7] = 0;

    int n;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;

        stof fields[num];
        for (int i = 0; i < num; ++i)
            cin >> fields[i].name;
        for (int i = 0; i < num; ++i)
            cin >> fields[i].num;

        map<char, vector<int> > fieldnums;
        map<char, int> fieldcounts;

        for (int i = 0; i < num; ++i) {
            fieldnums[fields[i].name].pb(fields[i].num);
            ++fieldcounts[fields[i].name];
        }

        vector< pair<int, pair<int, char> > > sortstruct;
        map<char, int> fieldpos;
        int letters[] = {'H', 'W', 'G', 'E', 'S'};

        for (int i = 0; i < 5; ++i) {
            sortstruct.pb(mp(0, mp(0, letters[i])));
            fieldpos[letters[i]] = i;
        }

        foreach(fieldpos, it) {
            char name = it->st;

            foreach(fieldnums[name], nums) {
                sortstruct[fieldpos[name]].st += chance[*nums];
            }

            sortstruct[fieldpos[name]].nd.st = fieldcounts[name];
        }

        sortstruct.erase(remove_if(all(sortstruct), shouldDelete), sortstruct.end());

        sort(all(sortstruct));
        cout << sortstruct[0].nd.nd << endl;
    }

    return 0;
}

