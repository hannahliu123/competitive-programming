// USACO 2022 January Contest, Bronze
// Problem 3. Drought

// Didn't time, but took around 30 mins (after looking at the solution tho)

// Partial (brute force test cases 1-8)
// Check each possible ending value for the hunger levels of all the cows (from 0 to 
// the minimum given hunger level). For each possible ending hunger, check if it's
// possible for the cows to eat corn in pairs and all end up at the same level. I 
// actually didn't really figure out this brute force method in my over 2 hours of
// working this problem, so uh kudos to me let me coooook! Anyways, yeah this makes 
// sense. Next time I should just at least code out a partial solution if i get stuck

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        
        vector<int> height(N);
        int mnhunger{1000000000};
        for (int i{0}; i < N; ++i) {
            cin >> height[i];
            mnhunger = min(mnhunger, height[i]);
        }

        long long ans{1000000000};     // min bags of corn
        for (int i{0}; i <= mnhunger; ++i) {    // i is possible ending value
            vector<int> h = height;
            long long corn{0};
            for (int j{0}; j < N-1; ++j) {
                if (h[j]>i) {
                    int sub = min(h[j], h[j+1]) - i;
                    h[j] -= sub;
                    h[j+1] -= sub;
                    corn += 2*sub;
                }
            } for (int j{0}; j < N-1; ++j) {
                if (h[j] != h[j+1]) {
                    corn = 1000000000;
                    break;
                }
            }
            ans = min(ans, corn);
        }

        cout << (ans==1000000000? -1 : ans) << '\n';
    }
}
