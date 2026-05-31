#include <bits/stdc++.h>

#define int long long

using namespace std;

bool is_square(int n) {
    int x = (int)sqrtl(n) + 1;
    while (x * x > n) x--;
    return x * x == n;
}

int range_sum(int f, int t) {
    // Returns [f, t] range sum
    return (t - f + 1) * (f + t) / 2;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
