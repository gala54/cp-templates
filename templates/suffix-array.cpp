vector<int> SuffixArray(string& s) {
    s += '$';
    int n = s.length();
    vector<int> p(n), c(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return s[i] < s[j];
    });
    for (int i = 1; i < n; i++) {
        c[p[i]] = c[p[i - 1]] + (s[p[i]] > s[p[i - 1]]);
    }
    for (int k = 1; k < n; k = k * 2) {
        vector<int> q(n);
        for (int i = 0; i < n; i++) {
            q[i] = p[i] - k;
            if (q[i] < 0) {
                q[i] += n;
            }
        }
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            cnt[c[i]]++;
        }
        for (int i = 1; i < n; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            p[--cnt[c[q[i]]]] = q[i];
        }
        vector<int> d(n);
        for (int i = 1; i < n; i++) {
            auto x = make_pair(c[p[i]], c[(p[i] + k) % n]);
            auto y = make_pair(c[p[i - 1]], c[(p[i - 1] + k) % n]);
            d[p[i]] = d[p[i - 1]] + (x > y);
        }
        swap(c, d);
    }
    p.erase(p.begin());
    return p;
}