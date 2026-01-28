// Fair Photography

// Start: 6:46
// End: 7:26        40 mins!!

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("fairphoto.in", "r", stdin);
    // freopen("fairphoto.out", "w", stdout);
    int N; cin >> N;
    vector<pair<int,int>> cows(N);  // pos, breed
    for (int i{0}; i < N; ++i) {
        char breed;
        cin >> cows[i].first >> breed;
        if (breed == 'G') cows[i].second = 1;
        else cows[i].second = -1;
    }
    
    sort(cows.begin(), cows.end());
    int mxCont = 0, currCont = 0;
    int start = 0, end = 0;
    int contStart = -1, contEnd = -1;
    for (int i{1}; i < N; ++i) {
        if (cows[i].second == cows[i-1].second) {
            end = i; 
            currCont = cows[end].first - cows[start].first;
            if (currCont > mxCont) {
                contStart = start;
                contEnd = end;
                mxCont = currCont;
            }
        } else {
            start = i; end = i;
            currCont = 0;
        }
    }

    vector<int> pref(N+1, 0);
    unordered_map<int,pair<int,int>> track;   // min, max
    track[0] = {0,-1};
    for (int i{1}; i <= N; ++i) {
        pref[i] = pref[i-1]+cows[i-1].second;
        if (track.find(pref[i]) == track.end()) track[pref[i]] = {i,-1};
        else track[pref[i]].second = i;
    }

    int ans = mxCont;
    for (auto& p : track) {
        pair<int,int> mnmx = p.second;
        if (mnmx.second == -1) continue;
        int dist = cows[mnmx.second-1].first - cows[mnmx.first].first;
        ans = max(ans, dist);
    }

    cout << ans << endl;
}
