struct SegTree {
    int n;
    vector<i64> t;  
    SegTree (int _) {
        n = _;
        t.resize(4 * _);
    }  
    SegTree(const vector<int>& _) {
        n = _.size();
        t.resize(4 * n);
        build(1, 0, n - 1, _);
    }
    i64 join(i64 y, i64 z) {
        return y + z;
    }
    void build(int v, int l, int r, const vector<int>& _) {
        if (l == r) {
            t[v] = _[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m, _);
        build(2 * v + 1, m + 1, r, _);
        t[v] = join(t[2 * v], t[2 * v + 1]);
    }
    void modify(int v, int l, int r, int p, int val) {
        if (l == r) {
            t[v] = val;
            return;
        }
        int m = (l + r) / 2;
        if (p <= m) {
            modify(2 * v, l, m, p, val);
        } else {
            modify(2 * v + 1, m + 1, r, p, val);
        }
        t[v] = join(t[2 * v], t[2 * v + 1]);
    }
    i64 query(int v, int l, int r, int a, int b) {
        if (l > b || r < a) {
            return 0;
        }
        if (a <= l && r <= b) {
            return t[v];
        }
        int m = (l + r) / 2;
        return join(query(2 * v, l, m, a, b), query(2 * v + 1, m + 1, r, a, b));
    }
    void modify(int p, int val) {
        modify(1, 0, n - 1, p, val);
    }
    i64 query(int a, int b) {
        return query(1, 0, n - 1, a, b);
    }
};