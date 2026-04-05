#include <bits/stdc++.h>

using namespace std;

vector<int> split_equally(vector<int>& a) {
    // Returns all `parts` where `parts` is no of equal-sum subarrays
    int n = a.size();
    int tot = accumulate(a.begin(), a.end(), 0);
    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    vector<int> ans;
    for (int parts = 1; parts <= tot; parts++) {
        if (tot % parts != 0) continue;
        int target = tot / parts;
        bool ok = false;
        vector<int> cnt(target);
        for (int i = 0; i < n; i++) {
            if (++cnt[pref[i] % target] == parts) {
                ok = true;
                break;
            }
        }
        if (ok) ans.push_back(parts);
    }
    return ans;
}
