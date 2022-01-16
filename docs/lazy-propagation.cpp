#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

// ------------------- template start -------------------
struct SegTree {...};
// -------------------  template end  -------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /*
    SegTree(int _):                      constructs a segment tree of length _ with all elements initialized to 0 

    SegTree(vector<int> _):              constructs a segment tree on vector _
    
    void modify(int a, int b, int val):  increases all elements in the range [a...b] by val
    
    i64 query(int a, int b):             returns the sum of all elements in the range [a...b] 
    */

    SegTree t(6);

    t.modify(0, 2, 1);
    cout << t.query(0, 2) << '\n'; // output: 3

    t.modify(2, 3, 2);
    cout << t.query(1, 4) << '\n'; // output: 6

    t.modify(3, 5, -2);
    cout << t.query(0, 5) << '\n'; // output: 1
}