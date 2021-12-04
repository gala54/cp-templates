struct Tree {
    int n, l;
    vector<int> dep;
    vector<vector<int>> e, f;
    Tree(int _) {
        n = _;
        l = ceil(log2(_));
        dep.resize(_);
        e.resize(_);
        f.assign(_, vector<int>(l));
    }
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
    void setRoot(int r) {
        function<void(int, int)> dfs = [&](int u, int p) {
            f[u][0] = p;
            for (int i = 1; i < l; i++) {
                f[u][i] = f[f[u][i - 1]][i - 1];
            }
            for (int v : e[u]) {
                if (v != p) {
                    dep[v] = dep[u] + 1;
                    dfs(v, u);
                }
            }
        };
        dfs(r, r);
    }
    int dis(int u) {
        return dep[u];
    }
    int dis(int u, int v) {
        // todo
        return 0;
    }
    int lift(int u, int d) {
        for (int i = l - 1; i >= 0; i--) {
            if (d & (1 << i)) {
                u = f[u][i];
            }
        }
        return u;
    }
    int lca(int u, int v) {
        // todo
        return 0;
    }
};