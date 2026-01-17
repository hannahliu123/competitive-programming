// D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string s;
        cin >> N >> s;

        vector<pair<int,int>> right{};  // cnt, # of ) after
        vector<pair<int,int>> left{};   // # of ( needed in front, # of ) after
        int cnt_r = 0, cnt_l = 0;
        for (int i{0}; i < N; ++i) {
            if (s[i] == '(') {
                cnt_r++;
                right.push_back({cnt_r, (N/2)-cnt_l});
            } else if (s[i] == ')') {
                left.push_back({cnt_r+1, cnt_r+1-cnt_l});
                cnt_l++;
            }
        }

        sort(left.begin(), left.end());

        int ans = -1;
        for (auto& p : right) {
            int li = upper_bound(left.begin(), left.end(), p) - left.begin();
            li--;
            if (li>=0 && li<left.size()) {
                auto p2 = left[li];
                if (p2.first==p.first && p2.second<=p.second) {
                    ans = max(ans, max(p.first, p.second)*2);
                }
            }
        }

        cout << ans << endl;
    }
}
