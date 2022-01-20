#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include "dsu.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dsu d(8);
    d.merge(1, 5);
    d.merge(2, 4);
    d.merge(4, 5);
    d.merge(0, 7);

    for (int i = 0; i < 8; i++) {
        cout << d.size(i) << ' ';
    }
    // output: 2 4 4 1 4 4 1 2
}