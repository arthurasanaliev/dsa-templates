#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    // 0-indexed Sum Seg Tree
    const int DEF = 0;

    int n;
    vector<long long> st;

    long long f(long long a, long long b) {
        return a + b;
    }

    SegmentTree(vector<int>& a) {
        n = a.size();
        st.assign(n * 4, DEF);
        build(a, 1, 0, n - 1);
    }

    void build(vector<int>& a, int x, int lx, int rx) {
        if (lx == rx) {
            st[x] = a[lx];
            return;
        }
        int m = lx + (rx - lx) / 2;
        build(a, x * 2, lx, m);
        build(a, x * 2 + 1, m + 1, rx);
        st[x] = f(st[x * 2], st[x * 2 + 1]);
    }

    void update(int i, int v) {
        update(i, v, 1, 0, n - 1);
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (lx == rx) {
            st[x]  = v;
            return;
        }
        int m = lx + (rx - lx) / 2;
        if (i <= m) {
            update(i, v, x * 2, lx, m);
        } else {
            update(i, v, x * 2 + 1, m + 1, rx);
        }
        st[x] = f(st[x * 2], st[x * 2 + 1]);
    }

    long long query(int l, int r) {
        return query(l, r, 1, 0, n - 1);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        if (r < lx || rx < l) {
            return DEF;
        }
        if (l <= lx && rx <= r) {
            return st[x];
        }
        int m = lx + (rx - lx) / 2;
        auto s1 = query(l, r, x * 2, lx, m);
        auto s2 = query(l, r, x * 2 + 1, m + 1, rx);
        return f(s1, s2);
    }
};
