#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MOD1 = 998244353;

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res = res * i % MOD;
    }
    return res;
}

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

int inv(int n) {
    return binpow(n, MOD - 2);
}

int comb(int a, int b) {
    if (b < 0 || b > a) return 0;
    return fact(a) * inv(fact(b) * fact(a - b) % MOD) % MOD;
}