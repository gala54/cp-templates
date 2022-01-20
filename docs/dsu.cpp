#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include "dsu.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /*
    dsu(int n):                  constructs a dsu object on a graph with n vertices

    int find(int x):             returns the leader of the component containing node x

    bool same(int x, int y):     returns true if nodes x and y are in the same component, false otherwise

    bool merge(int x, int y):    merges the components of nodes x and y; the leader of the component containing x
                                 becomes the leader of new merged copmonent; returns false if x and y
                                 are already in the same component, true otherwise

    int size(int x): returns the size of the component containing x;
    */

    dsu d(8);
    d.merge(1, 5);
    d.merge(2, 4);
    d.merge(4, 5);
    d.merge(0, 7);

    for (int i = 0; i < 8; i++) {
        cout << d.size(i) << ' ';
    }
    // output: 2 4 4 1 4 4 1 2
}