struct Tree {
    int n, l;
    vector<int> dep, in, out;
    vector<vector<int>> e, f;
    Tree(int _) {
        n = _;
        l = ceil(log2(_ + 1));
        dep.resize(_);
        in.resize(_);
        out.resize(_);
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
        int timer = 0;
        dep[r] = 0;
        function<void(int, int)> dfs = [&](int u, int p) {
            in[u] = timer++;
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
            out[u] = timer++;
        };
        dfs(r, r);
    }
    int dis(int u) {
        return dep[u];
    }
    int dis(int u, int v) {
        return dis(u) + dis(v) - 2 * dis(lca(u, v));
    }
    int lift(int u, int d) {
        for (int i = l - 1; i >= 0; i--) {
            if (d & (1 << i)) {
                u = f[u][i];
            }
        }
        return u;
    }
    bool isAncestor(int u, int v) {
        return (in[u] <= in[v] && out[u] >= out[v]);
    }
    int lca(int u, int v) {
        if (isAncestor(u, v)) {
            return u;
        }
        if (isAncestor(v, u)) {
            return v;
        }
        for (int i = l - 1; i >= 0; i--) {
            if (!isAncestor(f[u][i], v)) {
                u = f[u][i];
            }
        }
        return f[u][0];
    }
};