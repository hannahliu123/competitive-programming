// USACO 2020 December Contest, Silver
// Problem 2. Rectangular Pasture

// Redo using editorial 😢

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> coord(N);
    for (auto& p : coord) cin >> p.second >> p.first;   // y, x (for now)

    sort(coord.begin(), coord.end());   // coordinate compress y-values
    for (int i{0}; i < N; ++i) {
        coord[i].first = i+1;
        swap(coord[i].first, coord[i].second);  // swap y & x
    }

    sort(coord.begin(), coord.end());   // coordinate compress x-values
    for (int i{0}; i < N; ++i) coord[i].first = i+1;

    // build 2D prefix sum from top left corner (1-indexed because we will be 
    // subtracting from i and j)
    vector<vector<int>> pref(2501, vector<int>(2501, 0));  // 1-indexed
    // add cows to 2D prefix array
    for (int i{0}; i < N; ++i) pref[coord[i].first][coord[i].second] = 1;
    // compute all idicies of/build the 2D prefix array
    for (int i{1}; i <= 2500; ++i) {
        for (int j{1}; j <= 2500; ++j) {
            pref[i][j] += (pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]);
        }
    }

    sort(coord.begin(), coord.end(), [](auto& p1, auto& p2){return p1.second < p2.second;});
    long long ans{N+1};     // account for single cow subarrays & empty subarray
    // calculate the answer by looping through all the cows. For each cow, loop
    // loop through all other cows with an y-value after it (sorted by y-values)
    // and see how many subarrays we can get with that y-value boundary. To
    // calculate this, multiple the number of subsets available using the cows
    // above the box by the number of subsets available using the cows below the
    // box using the 2D prefix sum array to help. 
    for (int i{1}; i < N; ++i) {  // y-val of 1st coord
        for (int j{i+1}; j <= N; ++j) {  // y-val of 2nd coord
            int min_x = min(coord[i-1].first, coord[j-1].first);
            int max_x = max(coord[i-1].first, coord[j-1].first);
            // calculate number of cows above the min/max_x bounding box but still 
            // within the i to j interval using 2D prefix sums
            int above = pref[min_x-1][j] - pref[min_x-1][i-1];
            int a = pref[2500][j], b = pref[2500][i-1], c = pref[max_x][j], d = pref[max_x][i-1];
            int below = pref[2500][j] - pref[2500][i-1] - pref[max_x][j] + pref[max_x][i-1];
            ans += (above+1)*(below+1);
        }
    }

    cout << ans << endl;
}
