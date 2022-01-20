#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include "rmq.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {1, 2, 8, 0, -1, 11, 3, 7};
    RMQ<int> r(a);

    cout << r.query(0, 7) << '\n'; // output: -1
    cout << r.query(0, 3) << '\n'; // output: 0
    cout << r.query(5, 7) << '\n'; // output: 3

    vector<pair<int, int>> b = {{3, 1}, {0, 3}, {-1, 2}, {2, 4}};
    RMQ<pair<int, int>> t(b);

    auto result = t.query(0, 3);
    cout << result.first << ' ' << result.second << '\n'; // output: -1 2
}