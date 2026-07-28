// J. Worldwide Playlist - R1700

// Start: 2:38
// End: 3:26        48 mins

// this was really easy except i struggled a bit on implementation. if i just mapped it out on
// paper a bit better then it wouldn't have been an issue.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D; cin >> N >> D;
    vector<pair<int,int>> song(N+1);
    vector<int> a(N);
    vector<int> b(N);
    for (int i=0; i < N; i++) {
        cin >> a[i];
        song[a[i]].first = i;
    }
    for (int i=0; i < N; i++) {
        cin >> b[i];
        song[b[i]].second = i;
    }

    long long ans = 0;
    vector<long long> skips(N);
    int prev_idx = -1;
    for (int i=0; i < N; i++) {
        if (song[b[i]].first > prev_idx) {
            skips[i] = song[b[i]].first - prev_idx - 1;
        } else {
            skips[i] = song[b[i]].first + N - prev_idx - 1;
        } prev_idx = song[b[i]].first;
        ans += skips[i];
    }
    cout << ans << '\n';

    for (int i=0; i < D-1; i++) {
        int c, x, y; cin >> c >> x >> y;
        x--; y--;
        if (c==1) {
            song[a[x]].first = y;
            song[a[y]].first = x;
            swap(a[x], a[y]);

            int bi1 = song[a[x]].second;
            int bi2 = song[a[y]].second;

            // recompute bi1, bi1+1, bi2, bi2+1
            vector<int> indexes{bi1, bi1+1, bi2, bi2+1};
            for (int idx : indexes) {
                if (idx >= N) continue;
                ans -= skips[idx];
                prev_idx = (idx==0? -1 : song[b[idx-1]].first);
                skips[idx] = song[b[idx]].first - prev_idx - 1;
                if (skips[idx] < 0) skips[idx] += N;
                ans += skips[idx];
            }
        } else {
            song[b[x]].second = y;
            song[b[y]].second = x;
            swap(b[x], b[y]);

            int bi1 = y;
            int bi2 = x;

            // recompute bi1, bi1+1, bi2, bi2+1
            vector<int> indexes{bi1, bi1+1, bi2, bi2+1};
            for (int idx : indexes) {
                if (idx >= N) continue;
                ans -= skips[idx];
                prev_idx = (idx==0? -1 : song[b[idx-1]].first);
                skips[idx] = song[b[idx]].first - prev_idx - 1;
                if (skips[idx] < 0) skips[idx] += N;
                ans += skips[idx];
            }
        }

        cout << ans << '\n';
    }
}