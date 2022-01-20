#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include "fenwick.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Fenwick f(5);

    f.add(1, 3);
    f.add(4, -2);

    cout << f.sum(0, 2) << '\n'; // output: 3
    cout << f.sum(3, 4) << '\n'; // output: -2
    cout << f.sum(0, 4) << '\n'; // output: 1
}