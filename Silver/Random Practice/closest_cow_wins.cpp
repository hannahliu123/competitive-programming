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
// time trying to simplfy my logic and make broader connections to the problem. i actually
// thought for a while there was no optimal way to greedily select where eactly to put cows,
// but in reality there was one and i just totally missed it. before i thought i had to deal
// with intervals overlapping eachothers' patches but i just missed the true ideal greedy
// solution

// oml this implementation took me over an hour im literally gonna crash out. there were just
// too many different arrays and indexes to keep track of and so many little details that pmo'd.
// something the editorial did was compute the total tastiness and one-cow subsequence tastiness
// separately but that honestly doesn't simplfy much. in my code, i set the allowed position 
// range [l1,r1] beforehand then increment pr until it goes outside. then i move on to the next
// start pos by incrementing pl. one edge case i didn't account for though was if the starting
// [l1,r1] subsequence didn't have a patch, but later on there was one within (l,r). to fix it,
// i just needed to start l1 at the first valid patch

// um i relaly hate 2 ptrs/sliding window now heh but in the future ig just like work it out
// more thoroughly on paper before implementing.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, M, N; cin >> K >> M >> N;
    vector<pair<int,int>> patch(K); // pos, tastiness
    vector<int> nhoj(M+1, -1);    // pos
    for (int i=0; i < K; i++) cin >> patch[i].first >> patch[i].second;
    for (int i=0; i < M; i++) cin >> nhoj[i+1];
    sort(patch.begin(), patch.end());
    sort(nhoj.begin(), nhoj.end());
    nhoj.push_back(1000000002);
    
    vector<long long> contr{};
    int pl = 0, pr = 0;
    for (int i=0; i < M+1; i++) {
        int l = nhoj[i], r = nhoj[i+1];
        int len = (r-l+1)/2 - 1; 

        long long total = 0, mx = 0;
        long long curr = 0;   // from position l1 to r1
        while (pl<K && patch[pl].first < l) pl++;
        if (pl >= K) break;
        pr = pl;

        int l1 = patch[pl].first, r1 = min(r-1, l1+len);      // inclusive
        if (i==0 || i==M) r1=r-1;

        while (l1 < r && pr<K && patch[pr].first < r) {
            while (pr<K && patch[pr].first <= r1) {
                curr += patch[pr].second;
                total += patch[pr].second;
                pr++;
            }
            mx = max(mx, curr);
            curr -= patch[pl++].second;
            if (pl >= K) break;
            l1 = patch[pl].first;
            r1 = min(max(r1, l1+len), r-1);
        }

        if (i==0 || i==M) contr.push_back(total);
        else {
            contr.push_back(mx);            // first cow
            contr.push_back(total-mx);      // second cow
        }
    } sort(contr.rbegin(), contr.rend());

    long long ans = 0;
    for (int i=0; i < N; i++) {
        if (i==contr.size()) break;
        ans += contr[i];
    }

    cout << ans << '\n';
}