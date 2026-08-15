// C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> a(N);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());

    int curr_idx = lower_bound(a.begin(), a.end(), 0) - a.begin();
    if (curr_idx==N) curr_idx--;
    else if (curr_idx>0 && abs(0-a[curr_idx-1]) <= abs(0-a[curr_idx])) curr_idx--;
    vector<pair<int,int>> near(N);
    for (int i=0; i < N; i++) {
        near[i] = {i-1,i+1};
    }

    long long ans = abs(a[curr_idx]);
    while (true) {
        int left = near[curr_idx].first, right = near[curr_idx].second;
        int ldist = 0, rdist = 0;
        if (left != -1) {
            near[left].second = near[curr_idx].second;
            ldist = a[curr_idx]-a[left];
        } if (right != N) {
            near[right].first = near[curr_idx].first;
            rdist = a[right]-a[curr_idx];
        } near[curr_idx] = {-1,-1};
        if (ldist==0 && rdist==0) break;
        if (rdist == 0 || (ldist>0 && ldist <= rdist)) {
            curr_idx = left;
            ans += ldist;
        } else {
            curr_idx = right;
            ans += rdist;
        }
    }

    cout << ans << '\n';
}