#include <bits/stdc++.h>

using namespace std;

int lis(vector<int>& a) {
    vector<int> dp;
    for (int x : a) {
        if (dp.empty() || dp.back() < x) {
            dp.push_back(x);
        } else {
            auto it = lower_bound(dp.begin(), dp.end(), x);
            *it = x;
        }
    }
    return dp.size();
}
