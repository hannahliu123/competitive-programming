#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int>> ans;

void dfs(vector<int>& v, int start) {
    ans.push_back(v);
    for (int i=start; i <= min(N,v[0]); i++) {
        vector<int> v1 = v;
        v1[0] -= i;
        v1[i-1]++;
        dfs(v1, i);
    }
}

int main() {
    cin >> N >> K;
    ans.clear();

    vector<int> a(N, 0);
    a[0] = K;
    dfs(a, 2);

    sort(ans.begin(), ans.end());
    for (auto& v : ans) {
        for (auto & i : v) cout << i << ' ';
        cout << '\n';
    }
}