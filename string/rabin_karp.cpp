#include <bits/stdc++.h>

using namespace std;

#define int long long

const int P1 = 53, P2 = 59;
const int M1 = 1e9 + 7, M2 = 1e9 + 9;

int binpow(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b /= 2;
    }
    return res;
}

inline int letter_id(char c) {
    return ('a' <= c && c <= 'z') ? c - 'a' + 1 : c - 'A' + 27;
}

inline int roll(int h, int out_val, int in_val, int p, int pw, int m) {
    h = (h - out_val * pw % m + m) % m;
    return (h * p + in_val) % m;
}

array<int, 2> double_hash(const string& s) {
    // polynomial rolling double-hash function
    int h1 = 0, h2 = 0;
    for (char c : s) {
        int x = letter_id(c);
        h1 = (h1 * P1 + x) % M1;
        h2 = (h2 * P2 + x) % M2;
    }
    return {h1, h2};
}

int rabin_karp(const string& s, const string& t) {
    int n = s.size(), m = t.size();
    if (m > n) return 0;

    auto [h1, h2] = double_hash(t);
    auto [curr1, curr2] = double_hash(s.substr(0, m));

    int pw1 = binpow(P1, m - 1, M1);
    int pw2 = binpow(P2, m - 1, M2);

    int ans = (h1 == curr1 && h2 == curr2);
    for (int i = m; i < n; i++) {
        int x_prev = letter_id(s[i - m]);
        int x_curr = letter_id(s[i]);

        curr1 = roll(curr1, x_prev, x_curr, P1, pw1, M1);
        curr2 = roll(curr2, x_prev, x_curr, P2, pw2, M2);

        if (curr1 == h1 && curr2 == h2) ans++;
    }

    return ans;
}
