// C

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> l(N);
        vector<int> r(N);
        vector<int> u(N);
        vector<int> v(N);
        for (int i=0; i < N; i++) {
            cin >> l[i] >> r[i] >> u[i] >> v[i];
        }

        int nxt = 1;
        priority_queue<pair<int,int>> pq{}; // i, j
        for (int i=0; i < N; i++) {
            if (nxt<l[i] || nxt>r[i]) {
                pq.push({i,nxt});
                nxt++;
            }
        }

        nxt = 1;
        while (!pq.empty()) {
            int idx = pq.top().first;
            int j = pq.top().second;
            pq.pop();

            if (nxt>=u[idx] && nxt<=v[idx]) {   // invalid!
                for (int i=idx+1; i < N; i++) {
                    if (j<l[i] || j>r[i]) {
                        pq.push({i,j});
                        j++;
                    }
                }
                nxt = 1;
            } else nxt++;
        }
        
        cout << nxt-1 << '\n';
    }
}