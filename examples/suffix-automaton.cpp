#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include "suffix-automaton.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    SuffixAutomaton s("abbecdbadc"); // output: ab

    cout << s.lcs("abc") << '\n';
    cout << s.lcs("abecaabd") << '\n'; // output: bec

    s.add('c');

    cout << s.lcs("dadcc") << '\n'; // output: adcc

    cout << (s.contains("bbec") ? "true" : "false") << '\n'; // otuput: true
}