// D. Xmas or Hysteria - R1700

// Start: 8:52
// End: 10:11       1 hr 19 mins

// ugh this lowkey got kinda messy but it wasnt too hard :) basically just greedy imo
// but i def could've solved this quicker if i cleaned up my implementation cos the
// indexing kidna tripped me up.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        vector<pair<int,int>> a(N);
        for (int i=0; i<N; i++) {
            cin >> a[i].first;
            a[i].second = i+1;
        } sort(a.begin(), a.end());   // l -> g
        long long sum = 0;
        for (int i=0; i<N-1; i++) {
            sum += (long long)a[i].first;
        }

        if (M > N/2 || (M==0 && sum<a[N-1].first)) {
            cout << -1 << '\n'; continue;
        }

        
        if (M==0) {
            cout << N-1 << '\n';
            int i=0;
            while (a[N-1].first > a[N-2].first) {
                cout << a[i].second << ' ' << a[N-1].second << '\n';
                a[N-1].first -= a[i].first; i++;
            }
            while (i < N-1) {
                cout << a[i].second << ' ' << a[i+1].second << '\n';
                i++;
            }
        } else {
            cout << N-M << '\n';
            int rep = N-M-M;
            if (N%2==0) rep++;
            for (int i=0; i < rep; i++) {
                cout << a[i+1].second << ' ' << a[i].second << '\n';
            } 
            for (int i=rep+2; i < N; i+=2) {
                cout << a[i].second << ' ' << a[i-1].second << '\n';
            } if (N%2==1) cout << a[N-1].second << ' ' << a[N-2].second << '\n';
        }
    }
}