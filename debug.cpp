string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string(string(s));
}

template<class A, class B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class A, class B, class C>
string to_string(tuple<A, B, C> t) {
    return "(" + 
        to_string(get<0>(t)) + ", " + 
        to_string(get<1>(t)) + ", " +
        to_string(get<2>(t)) +
    ")";
}

template<class T>
string to_string(T a) {
    string res = "{";
    bool first = true;
    for (auto i : a) {
        res += (first ? "" : ", ") + to_string(i);
        first = false;
    }
    res += "}";
    return res;
}

template<class... T>
void print(T... args) {
    (..., (cerr << ' ' << to_string(args)));
    cerr << endl;
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", print(__VA_ARGS__)
#else
#define debug(...) "MJ >> LAMELO"
#endif