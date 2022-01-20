#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include "lca.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LCA t(7);
    t.addEdge(0, 1);
    t.addEdge(0, 2);
    t.addEdge(1, 3);
    t.addEdge(1, 4);
    t.addEdge(2, 5);
    t.addEdge(2, 6);

    t.gen(0);

    cout << t.get(3, 4) << '\n'; // output: 1
    cout << t.get(5, 6) << '\n'; // output: 2
    cout << t.get(4, 5) << '\n'; // output: 0
    cout << t.get(2, 2) << '\n'; // output: 2
}