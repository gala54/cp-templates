// verification: https://www.spoj.com/problems/HORRIBLE/
struct SegTree {
    int n;
    vector<i64> t, tag;    
    SegTree(int _) {
        n = _;
        t.resize(4 * n);
        tag.resize(4 * n);
    }
    SegTree(vector<int>& _) {
        n = _.size();
        t.resize(4 * n);
        tag.resize(4 * n);
        build(1, 0, n - 1, _);
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
    i64 join(i64 y, i64 z) {
        return y + z;
    }
    void push(int v, int l, int r) {
        int m = (l + r) / 2;
        t[2 * v] += (m - l + 1) * tag[v];
        t[2 * v + 1] += (r - m) * tag[v];
        tag[2 * v] += tag[v];
        tag[2 * v + 1] += tag[v];
        tag[v] = 0;
    }
    void modify(int v, int l, int r, int a, int b, i64 val) {
        if (l > b || r < a) {
            return;
        }
        if (a <= l && r <= b) {
            t[v] += (r - l + 1) * val;
            tag[v] += val;
            return;
        }
        push(v, l, r);
        int m = (l + r) / 2;
        modify(2 * v, l, m, a, b, val);
        modify(2 * v + 1, m + 1, r, a, b, val);
        t[v] = join(t[2 * v], t[2 * v + 1]);
    }
    i64 query(int v, int l, int r, int a, int b) {
        if (l > b || r < a) {
            return 0;
        }
        if (a <= l && r <= b) {
            return t[v];
        }
        push(v, l, r);
        int m = (l + r) / 2;
        return join(query(2 * v, l, m, a, b), query(2 * v + 1, m + 1, r, a, b));
    }
    void modify(int a, int b, int val) {
        modify(1, 0, n - 1, a, b, val);
    }
    i64 query(int a, int b) {
        return query(1, 0, n - 1, a, b);
    }
};