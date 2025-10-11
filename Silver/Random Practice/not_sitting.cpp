// CF - B. Not Sitting - R1300

// I read the editorial cos i was stuck. I figured out the basic greedy facts (like tina is
// always in the corners, but i focused too much on the idea that ralph chose a seat in the 
// middle. In reality, ralph's order of chosing seat didn't even matter because the answer 
// is always least to greatest anyways

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int R, C;
        cin >> R >> C;
        
        vector<int> ans{};
        for (int r{0}; r < R; ++r) {
            for (int c{0}; c < C; ++c) {
                int max_dist = r+c;
                max_dist = max(max_dist, abs(r-(R-1))+c);
                max_dist = max(max_dist, r+abs(c-(C-1)));
                max_dist = max(max_dist, abs(r-(R-1))+abs(c-(C-1)));
                ans.push_back(max_dist);
            }
        }

        sort(ans.begin(), ans.end());
        for (auto i : ans) cout << i << ' ';
        cout << '\n';
    }
}
