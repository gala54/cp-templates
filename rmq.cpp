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