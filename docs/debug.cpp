#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

// ------------------- template start -------------------
...
// -------------------  template end  -------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /*
    to enable the debugger, compile with -DLOCAL flag
    */

    vector<int> a = {3, 2, 1, 4, 5};
    vector<pair<int, int>> b = {{3, 2}, {-1, 0}, {2, 3}};

    debug(a, b);
    // output: [a, b]: {3, 2, 1, 4, 5} {(3, 2), (-1, 0), (2, 3)}

    for (int L = 0; L < 3;  L++) {
        for (int R = L; R < 3; R++) {
            debug(L, R);
        }
    }
    /*
    output:
    [L, R]: 0 0
    [L, R]: 0 1
    [L, R]: 0 2
    [L, R]: 1 1
    [L, R]: 1 2
    [L, R]: 2 2
    */

    set<tuple<int, int, int>> s;
    s.emplace(1, 2, 3);
    s.emplace(4, 5, 6);
    debug(s);
    // output: [s]: {(1, 2, 3), (4, 5, 6)}

    vector<int> d = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        debug(i, d[i]);
    }
    /*
    output
    [i, d[i]]: 0 1
    [i, d[i]]: 1 2
    [i, d[i]]: 2 3
    [i, d[i]]: 3 4
    [i, d[i]]: 4 5
    */
}