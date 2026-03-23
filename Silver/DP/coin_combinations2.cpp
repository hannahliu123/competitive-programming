// CSES Problem Set - Coin Combinations II

// I should've approached this problem as picking coins in increasing order so
// i first only pick combinations using just c[0], then i can use c[0] and c[1],
// then i can use c[0] c[1] and c[2], then so on. this makes it so that you're
// building combinations layer by layer and guarentees that you won't double
// count anything because the dp vector will always store the number of distinct
// combinations for i but at each level. so for the c[0] only level, you can only
// use one coin type (very simple). then you add the next coin c[1] and see how
// many new combinations you can form with either c[0], c[1], or both. At this
// point we only used the first two coins. Then we add in c[2] and because we know
// the combinations previously stored in the dp vector are all unique, we can just
// add the number directly, creating combinations of c[2] with/without c[0] and/or
// c[1]. This works so well because you simply wont add earlier repeat combinations
// (ex. 2,3,5 or 5,2,3) because the five can't have been visited until the very 
// end which by then we will only have a 2,3 to add it to. its kinda hard to 
// explain but i do get why this works now

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X; cin >> N >> X;
    vector<int> c(N);
    for (auto& i : c) cin >> i;

    vector<int> ans(X+1, 0);
    ans[0] = 1;
    for (auto& coin : c) {
        for (int i{1}; i <= X; i++) {
            if (i-coin >= 0) ans[i] += ans[i-coin];
            ans[i] %= 1000000007;
        }
    }

    cout << ans[X] << endl;
}
