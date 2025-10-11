// USACO 2017 US Open Contest, Bronze
// Problem 3. Modern Art

// Start: 4:46
// End: 6:06        1 hr 20 mins

// Erm so before you implement the solutions, you're gonna wanna reread the 
// problem and make sure you're solving for the right thing. Luckily, my 
// interpretation wasn't like THAT off, so i was able to salvage it. But I 
// could've shaved off like a solid 5-10 minutes if it weren't for that, so
// womp womp :( 

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    int N;  // size of canvas
    cin >> N;

    set<int> uniquenums{0};
    vector<vector<int>> canvas(N);
    vector<int> canvasi[10];
    vector<int> canvasj[10];
    for (int i{0}; i < N; ++i) {
        string colors;
        cin >> colors;
        for (int j{0}; j < N; ++j) {
            char color = colors[j]-'0';
            canvas[i].push_back(color);
            canvasi[color].push_back(i);
            canvasj[color].push_back(j);
            uniquenums.insert(color);
        }
    }

    vector<int> minmax[10];
    for (int color : uniquenums) {
        if (color != 0) {
            int mini = 10, maxi = -1, minj = 10, maxj = -1;
            for (int i{0}; i < canvasi[color].size(); ++i) {
                mini = min(mini, canvasi[color][i]);
                maxi = max(maxi, canvasi[color][i]);
                minj = min(minj, canvasj[color][i]);
                maxj = max(maxj, canvasj[color][i]);
            } 
            minmax[color].push_back(mini);
            minmax[color].push_back(maxi);
            minmax[color].push_back(minj);
            minmax[color].push_back(maxj);
        }
    }

    set<int> adj[10];
    for (int color : uniquenums) {
        if (color != 0) {
            for (int i{minmax[color][0]}; i <= minmax[color][1]; ++i) {
                for (int j{minmax[color][2]}; j <= minmax[color][3]; ++j) {
                    if (canvas[i][j] != color) {adj[color].insert(canvas[i][j]);}
                }
            }
        }
    }

    set<int> impossible{0};
    for (int i{1}; i < 10; ++i) {
        for (int num : adj[i]) {
            impossible.insert(num);
        }
    }

    int ans = 0;
    for (int num : uniquenums) {
        if (!impossible.count(num)) {++ans;}
    }

    cout << ans << endl;    
}
