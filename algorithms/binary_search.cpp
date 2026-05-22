#include <bits/stdc++.h>

using namespace std;

int last_true(int left, int right) {
    int l = left - 1, r = right;
    while (l < r) {
        int m = l + (r - l + 1) / 2;
        if (ok(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int first_true(int left, int right) {
    int l = left, r = right + 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (ok(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}
