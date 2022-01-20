#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include "modular.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Z two = 2;
    cout << two << '\n';              // output: 2
    cout << two.inv() << '\n';        // output: 500000004
    cout << power(two, 100) << '\n';  // output: 976371285

    init(20);
    cout << fac[5] << '\n';           // output: 120
    cout << fac[20] << '\n';          // output: 146326063
    cout << C(5, 2) << '\n';          // output: 10
    cout << C(20, 10) << '\n';        // output: 184756
}