#include <bits/stdc++.h>

using namespace std;

struct SparseTable {
    vector<vector<int>> st;

    int f(int a, int b) {
        return min(a, b);
    }

    SparseTable(vector<int>& a) {
        int n = a.size();
        int log = __lg(n) + 1;
        st.assign(n, vector<int>(log));
        for (int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
        for (int j = 1; j < log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int j = __lg(r - l + 1);
        return f(st[l][j], st[r - (1 << j) + 1][j]);
    }
};
