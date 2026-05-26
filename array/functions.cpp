#include <bits/stdc++.h>

using namespace std;

int mex(vector<int>& v) {
    int n = v.size();
    vector<bool> seen(n + 1);
    for (int x : v) {
        if (x >= 0 && x <= n) {
            seen[x] = true;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (!seen[i]) {
            return i;
        }
    }
    return 0;
}
