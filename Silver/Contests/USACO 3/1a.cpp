// The pattern will always repeat from the 0th to N-H+1th card FJ puts down because
// there is only ever one choice he can make for what card to put down, and bc his hand
// size is fixed, after he puts it down, it goes back into the pile, meaning if he
// continues to put down the best possible cards, he will encounter that one again and
// his hand would look like the same as before.
// After realizing that, you just needed a clean implementation for this problem. I 
// overcomplicated things and tracked a ton of variables when constructing my final
// solution. I also didn't realize it just started repeating from the start. knowing
// this, you can also sort the current hand (make each card a pair and track if is a
// win condition or not). Then you only really need to track how many wins per repitition
// and what the times of those wins are. and how long each repitition takes

// Upsolving time!

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, H;
    cin >> N >> H;
    vector<pair<int,int>> orig(N, make_pair(0,0)); // win(1)/not(0), moolizir
    for (int i{0}; i < N; ++i) {
        cin >> orig[i].second;
        orig[i].second *= -1;
    }
    int k; cin >> k;
    for (int i{0}; i < k; ++i) {
        int idx; cin >> idx; idx--;
        orig[idx].first = 1;
    }

    priority_queue<pair<int,int>> hand{};
    for (int i{0}; i < H; ++i) hand.push(orig[i]);  // draw H cards

    long long cycleLen = 0; // length of one repetition
    vector<long long> wins{};    // times of N-H+1 cards selected each repetition
    for (int i{0}; i <= N-H; ++i) {  // N-H+1 selections
        // play a card
        auto card = hand.top();
        cycleLen += -1*card.second;    // add the moolizir
        if (card.first == 1) wins.push_back(cycleLen);  // time of playing this win condition
        hand.pop();
        hand.push(orig[i+H]);
    }

    int Q; cin >> Q;
    while (Q--) {
        long long t; cin >> t;

        long long ans = t/cycleLen * wins.size();  // num complete cycles * win conditions per cycle
        long long i = upper_bound(wins.begin(), wins.end(), t%cycleLen) - wins.begin();
        ans += i;   // i is already 1-indexed
    
        cout << ans << endl;
    }
}

