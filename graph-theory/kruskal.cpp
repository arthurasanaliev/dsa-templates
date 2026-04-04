#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> e;
    void init(int n) { e = vector<int>(n, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool same(int x, int y) { return get(x) == get(y); }
    int size(int x) { return -e[get(x)]; }
    void unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
    }
};

int kruskal(int n, vector<array<int, 3>>& edges) {
    // MST (min)
    sort(edges.begin(), edges.end(), [&](auto& i, auto& j) {
        return i[2] < j[2];
    });
    DSU dsu;
    dsu.init(n);
    int ans = 0;
    for (auto& e : edges) {
        if (!dsu.same(e[0], e[1])) {
            dsu.unite(e[0], e[1]);
            ans += e[2];
        }
    }
    return (dsu.size(0) != n ? -1 : ans);
}
