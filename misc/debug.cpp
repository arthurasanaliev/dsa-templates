#include <bits/stdc++.h>

using namespace std;

// --- Debug Template Start ---
template<class T, class = void> struct is_cont : false_type {};
template<class T> struct is_cont<T, void_t<decltype(begin(declval<T>()))>> 
    : integral_constant<bool, !is_same_v<T, string>> {};

template<class A, class B> ostream& operator<<(ostream& os, const pair<A, B>& p);
template<class T, enable_if_t<is_cont<T>::value, int> = 0>
ostream& operator<<(ostream& os, const T& v) {
    os << '{'; string s; for (const auto& x : v) os << s << x, s = ", "; return os << '}';
}
template<class A, class B> ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
template<size_t I = 0, class... T>
enable_if_t<I == sizeof...(T)> pr_tup(ostream&, const tuple<T...>&) {}
template<size_t I = 0, class... T>
enable_if_t<I < sizeof...(T)> pr_tup(ostream& os, const tuple<T...>& t) {
    if (I) os << ", "; os << get<I>(t); pr_tup<I + 1>(os, t);
}
template<class... T> ostream& operator<<(ostream& os, const tuple<T...>& t) {
    os << '('; pr_tup(os, t); return os << ')';
}

void dbg() { cerr << endl; }
template<class H, class... T> void dbg(H h, T... t) { cerr << ' ' << h; dbg(t...); }
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", dbg(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// --- Debug Template End ---
