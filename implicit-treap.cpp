mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int x;
    i64 p = rng();
    int cnt;
    Node *l, *r;
    Node(int _) {
        x = _;
        cnt = 1;
        l = r = nullptr;
    }
};

int siz(Node* t) {
    return (t ? t->cnt : 0);
}

void update(Node* t) {
    t->cnt = 1 + siz(t->l) + siz(t->r);
}

pair<Node*, Node*> split(Node* t, int k) {
    if (k == 0) {
        return {nullptr, t};
    }
    if (siz(t) <= k) {
        return {t, nullptr};
    }
    pair<Node*, Node*> res;
    if (siz(t->l) >= k) {
        tie(res.first, t->l) = split(t->l, k);
        res.second = t;
    } else {
        tie(t->r, res.second) = split(t->r, k - siz(t->l) - 1);
        res.first = t;
    }
    update(t);
    return res;
}

Node* merge(Node *l, Node *r) {
    if (!l || !r) {
        return (l ? l : r);
    }
    Node *res = nullptr;
    if (l->p > r->p) {
        l->r = merge(l->r, r);
        res = l;
    } else {
        r->l = merge(l, r->l);
        res = r;
    }
    update(res);
    return res;
}

// unverified
void insert(Node *&t, int pos, int x) {
    auto [l, r] = split(t, pos);
    t = merge(merge(l, new Node(x)), r);
}

// unverified
void erase(Node *&t, int pos) {
    Node *l, *r, *del;
    tie(l, r) = split(t, pos);
    tie(del, r) = split(r, 1);
    t = merge(l, r);
    delete del;
}

int get_kth(Node *t, int k) {
    if (k == siz(t->l)) {
        return t->x;
    } else if (k < siz(t->l)) {
        return get_kth(t->l, k);
    }
    return get_kth(t->r, k - siz(t->l) - 1);
}