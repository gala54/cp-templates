#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include "segment-tree.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    SegTree a(5);
    a.modify(1, 3);
    a.modify(4, -2);
    cout << a.query(0, 2) << '\n'; // output: 3
    cout << a.query(3, 4) << '\n'; // output: -2
    cout << a.query(0, 4) << '\n'; // output: 1

    vector<int> v = {1, -2, 4, 5, -3};
    SegTree b(v);
    cout << b.query(0, 4) << '\n'; // output: 5
    cout << b.query(1, 3) << '\n'; // output: 7
    b.modify(3, 1);
    cout << b.query(0, 4) << '\n'; // output: 1

}