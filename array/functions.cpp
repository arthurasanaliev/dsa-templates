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

void next_perm(vector<int>& a) {
    sort(a.begin(), a.end());
    do {
        for (int x : a) cout << x << ' ';
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));
}
