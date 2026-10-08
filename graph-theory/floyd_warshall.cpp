#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;

vector<vector<int>> floyd_warshall(int n, vector<array<int, 3>>& edges) {
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (auto& [f, t, w] : edges) {
        dist[f][t] = dist[t][f] = min(dist[f][t], w);
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}
