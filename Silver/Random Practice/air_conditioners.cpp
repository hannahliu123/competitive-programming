// CF - E. Air Conditioners - R1500 - 09/23-24/2025

// Im reateempting this tomorrow (I read the editorial tho and i feel so freaking stupid lol)

// Im so mad how easy this problem relaly is. I wasted so much time and brainpower wokring on
// a solution that barely made sense. I should've stepped back way before i got so far and 
// invested into that solution. I can usually tell when my idea isn't going to work because of
// how complicated it is, but somethimes i just cant find it in me to scrap that idea beacuse
// i feel like MIGHT just work. I never does so i need to stop doing that. This is such a
// great example where the actual solution is so much simpler than i could've imagined. 

// All you needed to do for this problem was to iterate once form left to right and another
// time from right to left and see pick the minimal solution. This is because you always
// keep track of the most optimal value moving right, and if that value is no longer optimal
// you chose the other option and continue to move right. Likewise, you keep the most optimal
// value moving left and take the minimum of both. This solution is so straightforward, and
// it's not even like ive never seen this concept before! Idk how i didn't think of it, but ig
// it's because it not like a formal algorithm and i was soo preoccupied trying to make my
// messy solution work. I'm gonna make a note of it for next time

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> a(K);   // air conditioner positions
        for (auto& i : a) cin >> i;
        vector<int> t(K);   // air conditioner temperatures
        for (auto& i : t) cin >> i;

        vector<long long> ans(N, LLONG_MAX/2);
        for (int i{0}; i < K; ++i) {    // place all air conditioners
            ans[a[i]-1] = t[i]; // 0-indexed
        }

        for (int i{1}; i < N; ++i) {    // first go left -> right
            ans[i] = min(ans[i], ans[i-1]+1);
        }

        for (int i{N-2}; i >= 0; --i) {    // now go right -> left
            ans[i] = min(ans[i], ans[i+1]+1);
        }

        for (auto i : ans) {    // print final ans
            cout << i << ' ';
        } cout << endl;
    }
}
