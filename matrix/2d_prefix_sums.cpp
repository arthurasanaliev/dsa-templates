#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> get_2d_pref(vector<string>& grid) {
    // 1-indexed
    int n = grid.size(), m = grid[1].size();
    vector<vector<int>> pref(n, vector<int>(m));
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (grid[i][j] == '*');
        }
    }
    return pref;
}

int compute(vector<vector<int>>& pref, int y1, int x1, int y2, int x2) {
    return pref[y2][x2] - pref[y1 - 1][x2] - pref[y2][x1 - 1] + pref[y1 - 1][x1 - 1];
}
