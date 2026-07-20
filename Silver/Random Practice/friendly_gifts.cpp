// CF - E. Friendly Gifts - R1700

// 1 hr

// um this was like scarily straightforward that i began to really doubt if i had the
// right solution or not. the time complexity and memory limit kidna confused me because
// i knew I could do an O(N^2) solution but my brain kept wanting to optimize it. I also
// thought maybe the number of pairs would be too high but it will never exceed N^2. So
// i tried using an unordered set but that's not a freaking thing in C++ for some reason
// but i didn't even think of just using a 2d grid of booleans. 

// also i thought my prefsum thing was smart but bro i didn't even need it. i could've 
// just checked if mx-mn == r-l (indexes). this is because we're assuming we skipped all
// duplicates. So, if the max value - min value is equal to the number of the number of
// items selected - 1, then it's valid because all the other numbers must be between the
// max and the min and can't be duplicated.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        vector<int> prefSum(N+1, 0);
        for (int i=1; i <= N; i++) {
            prefSum[i] = prefSum[i-1]+i;
        }

        vector<vector<bool>> min_max(N+1, vector<bool>(N+1, false));
        int ans = 0;
        for (int i=0; i < N; i++) {
            unordered_set<int> seen{a[i]};
            int mn = a[i], mx = a[i], sum = a[i];
            min_max[mn][mx] = true;
            if (mx+1 <= N && min_max[mx+1][mx+1]) ans = max(ans, 1);
            if (mx-1 >= 0 && min_max[mx-1][mx-1]) ans = max(ans, 1);

            for (int j=i+1; j < N; j++) {
                if (seen.count(a[j])) break;
                if (a[j] > mx) mx = a[j];
                if (a[j] < mn) mn = a[j];
                sum += a[j]; seen.insert(a[j]);
                if (sum == prefSum[mx]-prefSum[mn-1]) {
                    min_max[mn][mx] = true;
                    if (mx-mn+mx+1 <= N && min_max[mx+1][mx-mn+mx+1]) {
                        ans = max(ans, mx-mn+1);
                    } if (mn-1-(mx-mn) >= 0 && min_max[mn-1-(mx-mn)][mn-1]) {
                        ans = max(ans, mx-mn+1);
                    }
                }
            }
        }

        cout << ans << endl;
    }
}