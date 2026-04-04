#include <bits/stdc++.h>

#define int long long

using namespace std;

const int M = 1e18;

vector<int> dijkstra(int n, int source, vector<vector<array<int, 2>>>& adj) {
    vector<int> dist(n, M);
    dist[source] = 0;
    set<array<int, 2>> st;
    st.insert({0, source});
    while (!st.empty()) {
        auto [d, v] = *st.begin();
        st.erase(st.begin());
        for (auto& [to, w] : adj[v]) {
            int new_d = d + w;
            if (new_d < dist[to]) {
                st.erase({dist[to], to});
                dist[to] = new_d;
                st.insert({dist[to], to});
            }
        }
    }
    return dist;
}
