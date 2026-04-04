#include <bits/stdc++.h>

#define int long long

using namespace std;

bool is_square(int n) {
    int x = (int)sqrtl(n) + 1;
    while (x * x > n) x--;
    return x * x == n;
}

int range_sum(int f, int t) {
    // [f, t] range sum
    return (t - f + 1) * (f + t) / 2;
}
