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
    SegTree(int _): constructs a segment tree of length _ with all elements initialized to 0 

    SegTree(vector<int> _): constructs a segment tree on vector _
    
    void modify(int p, int val): sets the value of index p to val
    
    i64 query(int l, int r): returns the sum of all elements in with indexes in range [l...r] 
    */

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