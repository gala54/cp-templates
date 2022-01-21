#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include "fenwick2.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Fenwick2 f(4, 4);
    f.add(0, 0, 1); //      1000
    f.add(1, 2, 1); //  ->  0010
    f.add(3, 0, 1); //      0001
    f.add(2, 3, 1); //      1000

    cout << f.sum(3, 3) << '\n'; // output: 4
    cout << f.sum(3, 1) << '\n'; // output: 2
    cout << f.sum(1, 2, 2, 3) << '\n'; // output: 2
}