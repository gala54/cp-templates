#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

// ------------------- template start -------------------
struct Flow {...};
// -------------------  template end  -------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /*
    Flow(int n): constructs a flow network object with n nodes and 0 edges

    void addEdge(int u, int v, int c): adds a directed edge from u to v with capacity c

    int maxFlow(int s, int t): returns the max flow from s to t
    */

    Flow f(6);
    f.addEdge(0, 1, 7);
    f.addEdge(0, 2, 4);
    f.addEdge(2, 1, 3);
    f.addEdge(1, 3, 5);
    f.addEdge(1, 4, 3);
    f.addEdge(2, 4, 2);
    f.addEdge(4, 3, 3);
    f.addEdge(3, 5, 8);
    f.addEdge(4, 5, 5);

    cout << f.maxFlow(0, 5) << '\n';
    // solves the example flow network in https://cp-algorithms.com/graph/edmonds_karp.html
}