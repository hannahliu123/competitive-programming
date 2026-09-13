#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        
        priority_queue<int> pq{};
        long long sum = 0;
        long long ans = LONG_LONG_MIN;
        for (int i=0; i < N; i++) {
            if (i<M-1) {
                pq.push(a[i]);
                sum += a[i];
            } else {
                ans = max(ans, (long long)M*a[i] - sum);
                if (!pq.empty() && a[i] < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(a[i]);
                    sum += a[i];
                }
            }
        }

        cout << ans << '\n';
    }
}