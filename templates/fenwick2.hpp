struct Fenwick2 {
    int n, m;
    vector<vector<int>> f;
    Fenwick2(int x, int y) {
        n = x;
        m = y;
        f.resize(n, vector<int>(m));
    }
    void add(int x, int y, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            for (int j = y + 1; j <= n; j += j & -j) {
                f[i - 1][j - 1] += v;
            }
        }
    }
    i64 sum(int x, int y) {
        i64 res = 0;
        for (int i = x + 1; i > 0; i -= i & -i) {
            for (int j = y + 1; j > 0; j -= j & -j) {
                res += f[i - 1][j - 1];
            }
        }
        return res;
    }
    i64 sum(int a, int b, int c, int d) {
        return sum(c, d) - sum(a - 1, d) - sum(c, b - 1) + sum(a - 1, b - 1);
    }
};