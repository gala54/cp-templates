#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include "fenwick.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /*
    Fenwick(int n):            creates a fenwick tree of size n with all elements intialized to 0

    void add(int x, int v):    increases position x by v

    i64 sum(int x):            returns the sum of all elements in the range [0...x]

    i64 sum(int l, int r):     returns the sum of all elements in the range [l...r]
    */  

    Fenwick f(5);

    f.add(1, 3);
    f.add(4, -2);

    cout << f.sum(0, 2) << '\n'; // output: 3
    cout << f.sum(3, 4) << '\n'; // output: -2
    cout << f.sum(0, 4) << '\n'; // output: 1
}