# Graph Theory Notes

## Tree Diameter
```cpp
vector<vector<int>> g;
int dist = 0, node = -1;
void dfs(int cur, int prv, int d) {
    for (int to : g[cur]) {
        if (to == prv) continue;
        dfs(to, cur, d + 1);
    }
    if (d > dist) {
        dist = d;
        node = cur;
    }
}
dfs(0, -1, 0);
dfs(node, -1, 0);
// dist is diameter
```
