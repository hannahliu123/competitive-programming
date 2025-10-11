// USACO 2019 February Contest, Bronze
// Problem 2. The Great Revegetation

// Start: 7:29
// End: 8:16        47 mins

// Okay so i could've solved this quicker if i recognized how small the bounds 
// were and decided to just brute force my way through this problem. I would've 
// saved a lot of time cos i was scared to make too many vectors and stuff. I
// really liked one of the usaco guide solutions where they initialized the answer
// vector to all start with 1. Then, when they looped through each index of the
// adjacency list, they looped through each of the elements (values i can't share
// the same type of grass as) to check if the answer of that value is equal to the
// answer of the current value. Okay nevermind i don't like this solution. Wth is
// going on huh. Why does it increment the previous value?? yeah ok ik i should 
// probably try to understand this but uh my solution's fine and imma have to like
// relearn my graph skills for silver anyways so uh bye bye imma study for math
// and bio cos i have tests tmr :(

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int N, M;      // pastures, cows
    cin >> N >> M;

    vector<int> ans(N+1);
    ans[1] = 1;

    vector<int> adj[N+1];
    for (int i{0}; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i{2}; i < N+1; ++i) {
        vector<bool> isinvalid(5);
        for (int j{1}; j < N+1; ++j) {
            for (auto num : adj[i]) {
                if (num == j) {
                    isinvalid[ans[j]] = true;
                }
            }
        } for (int k{1}; k < 5; ++k) {
            if (!isinvalid[k]) {
                ans[i] = k;
                break;
            }
        }
    }

    for (int i{1}; i < N+1; ++i) {
        cout << ans[i];
    } cout << endl;
}

// only passed 1 & 2
