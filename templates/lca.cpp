template<class T>
struct RMQ {
    int n, k = 25;
    vector<int> lg2;
    vector<vector<T>> t;
    RMQ() {}
    RMQ(const vector<T>& _) {
        int n = _.size();
        lg2.resize(n + 1);
        t.assign(n, vector<T>(k));
        for (int i = 2; i <= n; i++) {
            lg2[i] = lg2[i / 2] + 1;
        }
        for (int i = 0; i < n; i++) {
            t[i][0] = _[i];
        }
        for (int j = 1; j < k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                t[i][j] = min(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T query(int L, int R) {
        int i = lg2[R - L + 1];
        return min(t[L][i], t[R - (1 << i) + 1][i]);
    }
};

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