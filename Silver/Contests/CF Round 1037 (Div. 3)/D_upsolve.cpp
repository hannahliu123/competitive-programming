// HOLY MOLY I UPSOLVED THIS PROBLEM LIKE FIVE HUNDRED DIFFERENT TIME ALREADY BECAUSE
// THE EDITORIAL COMPLETELY THREW ME OFF. LIKE WTF MAN PRIORITY QUEUES AND HEAPS WHO?!?!
// BRO THIS ANSWER IS SO SIMPLE IT COULD BE A R800 PROBLEM WTF MAN. WHYD YOU START YAPPING
// ABOUT PRIORITY QUEUES AND NOT EVEN MENTION THAT THE SOLUTION IS LITERALLY JUST COMMON
// FREAKING SENSE. OMG YALL ARE GOIGN DOWN WTF. DEEP BREATHS HANNAH DEEP BREATHS

// Okay so I didn't read the problem very carefully... and so I kinda missed the part
// where it was specified that l <= real <= r so the real value is always between the
// left and right values. This means that the value of your coins should NEVER decrease,
// because if they decrease, you either reach a real value less than your original one, 
// or you can reach a greater value, but you would've been able to also reach that same
// value originally (before decreasing your coins value). So, this means that you can
// simply sort l from least -> greatest and set your coin value to the real value if 
// you current coins are between l & r (and if it's beneficial of course, where the real
// value is greater than your current value). Even if there was a higher possible value,
// you would still be able to reach that value after setting your coins to the lower value
// because that of the constraint of real being less than or equal to r.

// I think the trickiest part of identifying this solution is just realizing how purely
// greedy this problem is. I doubted myself SO MANY times and the answer I submitted to the
// contest was WAY more confusing than it should've been. If anything, I've learned to
// really read the problem and constraints carefully.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, coins;
        cin >> N >> coins;

        vector<vector<int>> casinos(N);
        for (int i{0}; i < N; ++i) {
            int l, r, real;
            cin >> l >> r >> real;
            casinos[i] = {l, r, real};
        }
        
        sort(casinos.begin(), casinos.end());   // least -> greatest
        for (int i{0}; i < N; ++i) {
            if (coins >= casinos[i][0] && coins <= casinos[i][1] && coins < casinos[i][2]) {
                coins = casinos[i][2];
            }
        }

        cout << coins << endl;
    }
}
