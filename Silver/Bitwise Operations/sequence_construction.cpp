// USACO 2025 US Open Contest, Silver
// Problem 1. Sequence Construction

// I spent exactly 1 hour on this solution but it gets WA on literally every test case
// except the first and second. now im starting to doubt if this greedy solution even
// works because in theory it should, but apparently not. im actually so confident that
// it works so now im just confused. we dont need long longs or anything so idk why it
// would WA.

// oohhhh okay so the reason it WA was because if the even and odds didnt match up, my
// code shifted a chain of 1s to the left, but that's actually not the most desireable
// configuration. instead, we could keep the chain there (note that the parity would
// be messed up) but then we can push back a 2 and 1 which has an odd sum of 3 (smallest
// possible whilst keeping an pop count XOR of 0). BUT to make things extra annoying,
// there is one edge case which happens to be shown in the first test case given to us
// where an even smaller contirbution can be made in this case, specifically when the
// parity doesn't match up but we used the value of 1 when building a originally to
// satisfy the xor constraint. See, if we used the value 1 to satisfy a pop count of 1
// yet the array was the wrong parity, we could just use 2 instead (which has an extra
// sum contribution of 1 instead of 3). However, note this is only more desireable if 
// we used 1 originally. this was actually the idea i based my code off of but i didn't
// account for the other 3 sum contribution idea

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int M, K; cin >> M >> K;

        vector<int> a{};
        int sum = 0;
        for (int i=0; i < 5; i++) {
            if (K & (1<<i)) {   // ith bit in K is turned on
                a.push_back((1<<(1<<i))-1);
                sum += a.back();
            }
        }

        bool kpop_even = (__builtin_popcount(K) % 2 == 0);
        bool m_even = (M % 2 == 0);
        if (kpop_even != m_even) {
            if (a[0] == 1) {
                a[0] = 2; sum++;
            } else {
                a.push_back(1);
                a.push_back(2);
                sum += 3;
            }
        }

        if (sum > M) {
            cout << -1 << '\n';
            continue;
        }

        int add = (M-sum)/2;
        a.push_back(add); a.push_back(add);
        
        cout << a.size() << '\n';
        for (auto& i : a) cout << i << ' ';
        cout << '\n';
    }
}