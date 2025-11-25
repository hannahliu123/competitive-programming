// USACO 2024 February Contest, Silver
// Problem 1. Target Practice II

// So i got the right idea with the non binary search solution and i figured out
// which corners need positive slopes and which ones need negative slopes. But my
// implementation for deciding the TR and BR corners was very sketchy and i tried
// a greedy solution which doesn't work for this problem. The binary search 
// solution is actually so big brain and it makes so much sense. All you need to 
// do is binary search on a max line and another binary search on a min line then
// calculate all the max slopes you need to satisfy that. The sort it and compare
// them to the pos and neg slopes you have (seperately). This time i did figure
// out that i needed to seperate pos and neg but I didn't get the binary search 
// part. tbh i considered it but i didn't really know how it would work. the 
// comparing slopes is very clever. k now imma try to implement it

// hehe im so happy this works even though i know the logic will work but like 
// still bro let me be proud. kinda sad i couldn't get this on my own but at least
// the reasoning makes sense to me. this was just realizing the pos and neg stuff
// (which i got) then realizing how you can use binary search twice to set upper
// and lower bounds but cleverly compute slope for each. i kinda tried to naively
// figure out which slopes match with which points, when you could skip that step
// entirely (i mean ig u could still figure that out with the current solution
// but it's not needed). This was kinda precomputing slopes during each iteration
// of binary search so i wonder if it's kinda dp? idrk hwo to identify dp tho so wtv

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        long long x1;
        cin >> N >> x1;

        vector<pair<int,int>> pos_pts;  // x,y for all pos slopes
        vector<pair<int,int>> neg_pts;
        vector<int> left_pts;
        for (int i{0}; i < N; ++i) {
            int y1, y2, x2;
            cin >> y1 >> y2 >> x2;
            neg_pts.push_back({x2,y2});
            pos_pts.push_back({x2,y1});
            left_pts.push_back(y1);
            left_pts.push_back(y2);
        }

        vector<int> pos{};  // slopes
        vector<int> neg{};
        for (int i{0}; i < 4*N; ++i) {
            int s; cin >> s;
            if (s > 0) pos.push_back(s);
            else neg.push_back(s);
        }

        if (pos.size() < N || neg.size() < N) {
            cout << -1 << endl;
            continue;
        }

        sort(pos.begin(), pos.end());   // least (1) -> greatest (9)
        sort(neg.begin(), neg.end());   // least (-9) -> greatest (-1)
        sort(left_pts.begin(), left_pts.end()); // least -> greatest
        for (int i{0}; i < 2*N; ++i) {  // lowest points want negative slopes
            if (neg_pts.size() < neg.size()) {
                neg_pts.push_back({x1, left_pts[i]});
            } else {
                pos_pts.push_back({x1, left_pts[i]});
            }
        }

        long long hi = LLONG_MAX/3, lo = 0;
        long long mx_y = LLONG_MIN, mn_y = LLONG_MAX;
        // binary search on the lowest possible max
        while (hi > lo) {
            long long mid = lo + (hi - lo)/2;   // rounding down
            // imagine y=mid as a line and check the minimum possible slope each
            // point requiring a negative slope must have (so the lowest possible
            // or steepest) to reach (0, mid)
            bool possible = true;
            vector<double> slopes{};
            for (auto p : neg_pts) {    // check each point requiring neg slope
                int x = p.first; int y = p.second;
                double slope = (y-mid)/x;
                slopes.push_back(slope);
            }
            sort(slopes.begin(), slopes.end()); // least -> greatest
            for (int i{0}; i < slopes.size(); ++i) {
                if (slopes[i] > 0 || neg[i] < slopes[i]) {
                    possible = false;
                    break;
                }
            }

            if (possible) hi = mid;
            else lo = mid+1;
        } mx_y = lo;
        
        hi = LLONG_MAX/3, lo = LLONG_MIN/3;
        // binary search on the highest possible min
        while (hi > lo) {
            long long mid = lo + (hi - lo + 1)/2;   // rounding up
            // imagine y=mid as a line and check the maximum possible slope each
            // point requiring a positive slope must have (so the highest possible
            // or steepest) to reach (0, mid)
            bool possible = true;
            vector<double> slopes{};
            for (auto p : pos_pts) {    // check each point requiring pos slope
                int x = p.first; int y = p.second;
                double slope = (y-mid)/x;
                slopes.push_back(slope);
            }
            sort(slopes.begin(), slopes.end()); // least -> greatest
            for (int i{0}; i < slopes.size(); ++i) {
                if (slopes[i] < 0 || pos[i] > slopes[i]) {
                    possible = false;
                    break;
                }
            }

            if (possible) lo = mid;
            else hi = mid-1;
        } mn_y = lo;

        cout << mx_y-mn_y << endl;
    }
}
