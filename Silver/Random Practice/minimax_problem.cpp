// CF - D. Minimax Problem - R2000

// Start: 11:06
// End: 11:58       56 mins

// YAYAYAYYAYAYYAYAY!!! im so happy i got that gut feeling that this would be a binary
// search + bitwise ops problem so quickly (mainly because M was so small <=8). I'm super
// happy i got the implementation too yipeeeeeeee

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;

    vector<vector<int>> a(N, vector<int>(M));
    for (int i=0; i < N; i++) {
        for (int j=0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    // binary serach on maximum possible min
    int lo=0, hi=1e9;
    pair<int,int> ans;
    while (lo != hi) {
        int mid = lo + (hi-lo+1) / 2;
        
        map<int,int> s{};   // binary value, index
        for (int i=0; i < N; i++) {
            int val = 1;    // 2^0
            int on = 0;
            for (int j=M-1; j >= 0; j--) {
                int x = a[i][j];
                if (x >= mid) on += val;
                val *= 2;
            } s[on] = i;
        }

        vector<pair<bool, int>> contains(256, {false,-1});
        contains[0] = {true,-1};
        for (int i=1; i < 256; i++) {
            for (auto& p : s) {
                int y = p.first & i;
                if (y == i) {
                    contains[i] = {true, p.second};
                    break;
                }
            }
        }

        bool pos = false;
        int all_on = (1<<M)-1;
        for (auto& p : s) {
            int y = p.first ^ all_on;
            if (contains[y].first) {
                pos = true;
                ans.first = p.second;
                ans.second = contains[y].second==-1? p.second : contains[y].second;
                break;
            }
        }

        if (pos) lo = mid;
        else hi = mid-1;
    }

    cout << ans.first+1 << ' ' << ans.second+1 << endl;
}