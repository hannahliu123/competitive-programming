// USACO 2021 December Contest, Silver
// Problem 1. Closest Cow Wins

// so um I spent over an hour on this and realized my solution DOESN'T work because I thought
// it was ideal to always select the largest intervals but in reality, there was a bigger
// conclusion you could make about this problem. Notice how wherever nhoj's cows are, an
// interval is created that is separate from all other intervals. Between two nhoj cows, 
// you can only at the very most place a cow that captures patches between those nhoj cows
// and not outside because the edge nhoj cows are closer to patches outside. ADDITIONALLY,
// you are able to take ALL patches between two nhoj cows using only two john cows by placing
// them at the ends right near the nhoj cows. For edge intervals, you only need 1 cow to
// claim everything. once you have all your intervals, you can evaluate them separately such
// that you can either place 1 or 2 cows in each interval (except just 1 on the leftmost and
// rightmost). if you place 2 cows, you get all patches. if you only place 1 cow at index i
// and nhoj's cows are at indexes l and r, you occupy the range ((l+i)/2, (r+i)/2), giving
// you a total length of (r-l)/2. to avoid dealing with complicated decimal positions, we
// can just slide that interval from l+1 to the end using two pointers. Once we have all 
// one-cow contributions, the two-cow contribution is simply all tastiness within each
// interval. To figure out how to optimally place cows, you need to realize that the
// contribution of adding the first cow will always be greater than the respective contr of
// adding the second cow in a given interval. Thus, it works to just have a sorted list of
// one-cow contr and (entire interval)-(one cow) as the second cow contr because we must
// encounter the larger one-cow contr before the two-cow contr. the reason this works is if
// you just placed the one cow in one of the positions you would've places one of the two
// cows, you'll get at least half of the two cow contr.

// this problem reiterates how its important to start approaching problems by making as many
// greedy observations as possible before trying to optimize anything. i went too deep into
// a solution that was overcomplicated and didn't actually work. i should instead spend more
// time trying to simplfy my logic and make broader connections to the problem

#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, M, N; cin >> K >> M >> N;
    vector<pair<int,int>> patch(K); // pos, tastiness
    vector<int> nhoj(M);    // pos
    for (int i=0; i < K; i++) {
        cin >> patch[i].first >> patch[i].second;
    } for (int i=0; i < M; i++) {
        cin >> nhoj[i];
    } sort(patch.begin(), patch.end());
    sort(nhoj.begin(), nhoj.end());
    
    vector<long long> contr{0};
    int idx1 = 0, idx2 = 0;
    while (patch[idx2].first < nhoj[0]) {    // leftmost
        contr[0] += patch[idx2++].second;
    } for (int i=0; i < M-1; i++) {
        int l = nhoj[i], r = nhoj[i+1];
        int len = (r-l+1)/2 - 1;
        int l1 = l+1, r1 = l1+len;     // inclusive

        long long total_contr = 0, mx_contr = 0;
        long long curr_contr = 0;   // from l1 to r1
        while (patch[idx1].first <= l) idx1++;
        idx2 = idx1;
        while (r1 <= r && patch[idx1].first <= r1) {
            while (patch[idx2].first <= r1) {
                curr_contr += patch[idx2].second;
                total_contr += patch[idx2].second;
                idx2++;
            }
            mx_contr = max(mx_contr, curr_contr);
            curr_contr -= patch[idx1++].second;
            l1 = patch[idx1].first; r1 = l1+len;
        }

        contr.push_back(mx_contr);              // first cow
        contr.push_back(total_contr-mx_contr);  // second cow
    }
    while (idx2<K && patch[idx2].first <= nhoj[M-1]) idx2++;     // rightmost
    if (idx2 < K) contr.push_back(0);
    while (idx2 < K) {
        contr[contr.size()-1] += patch[idx2++].second;
    } sort(contr.rbegin(), contr.rend());

    long long ans = 0;
    for (int i=0; i < N; i++) {
        if (i==contr.size()) break;
        ans += contr[i];
    }

    cout << ans << '\n';
}