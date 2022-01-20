#include "rmq.hpp"

struct LCA {
    int n;
    vector<int> dep, pos;
    vector<pair<int, int>> tour;
    vector<vector<int>> g;
    RMQ<pair<int, int>> r;
    LCA(int _) {
        n = _;
        dep.resize(n);
        pos.resize(n);
        g.resize(n);
    }
    LCA(vector<vector<int>>& _) {
        LCA(_.size());
        g = _;
    }
    void addEdge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void dfs(int u, int p = -1) {
        pos[u] = tour.size();
        tour.emplace_back(dep[u], u);
        for (int v : g[u]) {
            if (v != p) {
                dep[v] = dep[u] + 1;
                dfs(v, u);
                tour.emplace_back(dep[u], u);
            }
        }
    }
    void gen(int root) {
        dep[root] = 0;
        tour.clear();
        dfs(root);
        r = RMQ(tour);
    }
    int get(int u, int v) {
        int L = pos[u], R = pos[v];
        if (L > R) {
            swap(L, R);
        }
        return r.query(L, R).second;
    }
};