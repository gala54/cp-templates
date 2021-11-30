struct Tree {
    int n;
    vector<vector<int>> e;
    Tree(int _) : n(_), e(_) {}
    void addEdge(int a, int b) {
        e[a].push_back(b);
        e[b].push_back(a);
    }
    pair<int, int> max_d(int u, int p) {
        pair<int, int> res = {0, u};
        for (int v : e[u]) {
            if (v != p) {
                res = max(res, max_d(v, u));
            }
        }
        return {res.first + 1, res.second};
    }
    int diam() {
        auto [d, u] = max_d(0, 0);
        return max_d(u, u).first;
    }
};