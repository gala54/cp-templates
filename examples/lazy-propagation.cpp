#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include "lazy-propagation.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SegTree t(6);

    t.modify(0, 2, 1);
    cout << t.query(0, 2) << '\n'; // output: 3

    t.modify(2, 3, 2);
    cout << t.query(1, 4) << '\n'; // output: 6

    t.modify(3, 5, -2);
    cout << t.query(0, 5) << '\n'; // output: 1
}