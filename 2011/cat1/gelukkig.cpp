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


int next_num(int n)
{
    int ret = 0;
    while (n > 0) {
        int digit = n % 10;
        n /= 10;

        ret += digit * digit;
    }

    return ret;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;

        int mem[1000] = {0};
        mem[1] = 1;
        while (num) {
            num = next_num(num);
            if (mem[num])
                break;
            mem[num] = 1;
        }

        if (num == 1)
            cout << "JA" << endl;
        else
            cout << "NEE" << endl;

    }

    return 0;
}

