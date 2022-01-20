#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include "modular.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /*
    objects of type Z support arithmetic operations under a modulus P

    init(int n):            computes the factorial and inverse factorial of all integers from [0...n];
                            call before using C(int n, int k);

    fac[i]:                 stores i! modulo P

    iFac[i]:                stores modular inverse of i! modulo P

    Z C(int n, int k):      returns 0 if k < 0 or k > n; returns (n choose k) modulo P otherwise

    Z inv():                returns the modular inverse of an object Z

    power(T a, int b):      returns a ^ b modulo P in log(b) time;
                            note: if the result is large, cast a as type Z

    note: adjust the value of the modulus P as needed
    warning: operations work under the assumption that P is prime
    */

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