#include <bits/stdc++.h>

#define int long long

using namespace std;

const int M = 1e18;

bool negative_cycle(int n, vector<array<int, 3>>& edges) {
    // one-way edges, true if there is a negative cycle anywhere in the graph
    // dist = 0 everywhere acts like a fake source joined to every node with weight 0
    vector<int> dist(n, 0);
    for (int i = 0; i < n; i++) {
        bool relaxed = false;
        for (auto& [f, t, w] : edges) {
            if (dist[f] + w < dist[t]) {
                dist[t] = dist[f] + w;
                relaxed = true;
            }
        }
        if (!relaxed) return false;
    }
    return true; // still relaxing on n-th pass
}

pair<vector<int>, vector<bool>> bellman_ford(int n, int source, vector<array<int, 3>>& edges) {
    // one-way edges
    // dist[i] = shortest distance from source, M if unreachable
    // cycle[i] = true if a path from source to i can go through a negative cycle (dist[i] is -inf, ignore it)
    vector<int> dist(n, M);
    dist[source] = 0;
    for (int i = 0; i < n - 1; i++) {
        bool relaxed = false;
        for (auto& [f, t, w] : edges) {
            if (dist[f] != M && dist[f] + w < dist[t]) {
                dist[t] = dist[f] + w;
                relaxed = true;
            }
        }
        if (!relaxed) break;
    }
    // n-th pass: anything that still relaxes is on or after a negative cycle
    vector<bool> cycle(n, false);
    vector<vector<int>> adj(n);
    for (auto& [f, t, w] : edges) {
        adj[f].push_back(t);
        if (dist[f] != M && dist[f] + w < dist[t]) cycle[t] = true;
    }
    // everything reachable from those nodes is -inf too
    queue<int> q;
    for (int i = 0; i < n; i++) if (cycle[i]) q.push(i);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : adj[v]) {
            if (!cycle[to]) {
                cycle[to] = true;
                q.push(to);
            }
        }
    }
    return {dist, cycle};
}
