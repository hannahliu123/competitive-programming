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
        vector<pair<int,int>> pos(N*M, {-1,-1});
        for (int i=0; i < N; i++) {
            for (int j=0; j < M; j++) {
                int x; cin >> x;
                pos[x-1] = {i,j};
            }
        }

        map<char,pair<int,int>> m{
            {'L', {0,-1}}, {'R', {0,1}}, {'U', {-1,0}}, {'D', {1,0}} };
        pair<int,int> curr = {0,0};
        long long ans = 0;  // index in s
        for (int i=0; i < N*M; i++) {   // want to reach i from i-1
            int actions = 0;
            while (dist(curr,pos[i]) > actions) {
                pair<int,int> drift = m[s[ans%S]];
                curr.first = (curr.first+drift.first+N)%N;
                curr.second = (curr.second+drift.second+M)%M;
                ans++;
                actions++;
            } curr = pos[i];
        }

        cout << ans << '\n';
    }
}