// CF - B. Han Solo and Lazer Gun - R1400

// Start: 11:06
// End: 11:34

// Okay so I messed up here by thinking that I should take the abs() of the up/down and 
// left/right measurements, when in reality, it matters if it's positive/negative. I looked
// at my failed test case which I why I was able to debug it rather quickly. I think next
// time, though, I won't look at the test cases because I gotta learn how to identify these
// logic mistakes. Last time I messed up by incrementing i in a look instead of decrementing
// but this time it was purely logic based. To figure this this out, I could've easily seen
// the error by testing a bunch of random test cases. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x, y;
    cin >> N >> x >> y;

    vector<pair<int, int>> s(N);
    vector<bool> killed(N, false);
    for (auto& i : s) cin >> i.first >> i.second;
    
    int shots{0};
    for (int i{0}; i < N; ++i) {
        if (killed[i]) continue;
        shots++;
        long long right = s[i].first - x;
        long long up = s[i].second - y;
        for (int j{i}; j < N; ++j) {
            if (killed[j]) continue;
            long long curr_r = s[j].first - x;
            long long curr_u = s[j].second - y;
            if (curr_r*up == curr_u*right) {     // if proportional
                killed[j] = true;
            }
        }
    }

    cout << shots << endl;
}
