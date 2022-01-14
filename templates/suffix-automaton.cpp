struct Node {
    int len, link;
    map<char, int> e;
    Node(int a, int b) : len(a), link(b) {}
};
struct SuffixAutomaton {
    int last, cur;
    vector<Node> t;
    SuffixAutomaton() {
        last = 0;
        cur = 1;
        t.emplace_back(0, -1);
    }
    SuffixAutomaton(const string& _) : SuffixAutomaton() {
        for (char c : _) {
            add(c);
        }
    }
    void add(char c) {
        int add = cur++;
        t.emplace_back(t[last].len + 1, 0);
        int p = last;
        while (p != -1 && !t[p].e.count(c)) {
            t[p].e[c] = add;
            p = t[p].link;
        }
        if (p != -1) {
            int q = t[p].e[c];
            if (t[p].len + 1 == t[q].len) {
                t[add].link = q;
            } else {
                int clone = cur++;
                t.emplace_back(t[p].len + 1, t[q].link);
                t[clone].e = t[q].e;
                while (p != -1 && t[p].e[c] == q) {
                    t[p].e[c] = clone;
                    p = t[p].link;
                }
                t[q].link = t[add].link = clone;
            }
        }
        last = add;
    }
    bool contains(const string& s) {
        int u = 0;
        for (char c : s) {
            if (!t[u].e.count(c)) {
                return false;
            }
            u = t[u].e[c];
        }
        return true;
    }
    string lcs(const string& s) {
        int u = 0, l = 0, mx = 0, pos = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            while (u && !t[u].e.count(s[i])) {
                u = t[u].link;
                l = t[u].len;
            }
            if (t[u].e.count(s[i])) {
                u = t[u].e[s[i]];
                l++;
            }
            if (l > mx) {
                mx = l;
                pos = i;
            }
        }
        return s.substr(pos - mx + 1, mx);
    }
};