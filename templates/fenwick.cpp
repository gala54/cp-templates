struct Fenwick {
    int n;
    vector<int> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    i64 sum(int x) {
        i64 res = 0;
        for (int i = x + 1; i > 0; i -= i & -i) {
            res += a[i - 1];
        }
        return res;
    }
    i64 sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};