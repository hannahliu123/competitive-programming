// okay now that N*M <= 2*10^5, we can no longer just naively simulate all actions.
// Instead, we need a way to bundle and quickly compute the minimum number of actions
// required to reach each of N*M items in at most logarithmic time.

// wait i just realized binary serach works so perfectly here how did i not catch this
// earlier. obviously if you can reach the target after k drifts, you can also reach it
// after k+x drifts because you can just keep canceling out moves! so we're essentially
// binary searching on N+M (cos that's the max moves) and we can use a prefix array to
// keep track of the drifts

#include <bits/stdc++.h>
using namespace std;

int N, M;

int dist(pair<int,int> curr, pair<int,int> target) {
    int cx = curr.first, cy = curr.second;
    int tx = target.first, ty = target.second;
    int x = abs(cx - tx);
    x = min(x, min(cx,tx)+N-max(cx,tx));
    int y = abs(cy - ty);
    y = min(y, min(cy,ty)+M-max(cy,ty));
    return x+y;
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> N >> M;
        string s; cin >> s;
        int S = s.length();
        map<char,pair<int,int>> m{
            {'L', {0,-1}}, {'R', {0,1}}, {'U', {-1,0}}, {'D', {1,0}} };
        vector<pair<int,int>> pref(S+1, {0,0});
        for (int i=1; i <= S; i++) {
            pref[i] = pref[i-1];
            pair<int,int> drift = m[s[i-1]];
            pref[i].first += drift.first;
            pref[i].second += drift.second;
        }

        vector<pair<int,int>> pos(N*M, {-1,-1});
        for (int i=0; i < N; i++) {
            for (int j=0; j < M; j++) {
                int x; cin >> x;
                pos[x-1] = {i,j};
            }
        }

        pair<int,int> curr = {0,0};
        long long ans = 0;  // index in s
        for (int i=0; i < N*M; i++) {   // want to reach i from i-1
            int l=0, r=N+M;
            while (l < r) {
                int mid = l + (r-l)/2;  // number of actions
                int loop = mid/S;
                pair<int,int> newpos = {curr.first + pref[S].first*loop, curr.second + pref[S].second*loop};
                int end = (ans%S)+(mid%S);
                if (end > S) {
                    newpos.first += pref[S].first-pref[ans%S].first + pref[end-S].first;
                    newpos.first = (newpos.first+N)%N;
                    newpos.second += pref[S].second-pref[ans%S].second + pref[end-S].second;
                    newpos.second = (newpos.second+M)%M;
                } else {
                    newpos.first += pref[end].first-pref[ans%S].first;
                    newpos.first = (newpos.first+N)%N;
                    newpos.second += pref[end].second-pref[ans%S].second;
                    newpos.second = (newpos.second+M)%M;
                }

                if (dist(newpos,pos[i]) <= mid) r = mid;
                else l = mid+1;
            }
            ans += l;
            curr = pos[i];
        }

        cout << ans << '\n';
    }
}