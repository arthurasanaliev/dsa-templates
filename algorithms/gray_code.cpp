#include <bits/stdc++.h>

using namespace std;

vector<string> gray_code(int n) {
    vector<string> res = {"0", "1"};
    for (int i = 2; i <= n; i++) {
        int sz = res.size();
        for (int j = sz - 1; j >= 0; j--) {
            res.push_back(res[j]);
        }
        for (int j = 0; j < res.size(); j++) {
            if (j < res.size() / 2) res[j] += '0';
            else res[j] += '1';
        }
    }
    for (auto& x : res) reverse(x.begin(), x.end());
    return res;
}
