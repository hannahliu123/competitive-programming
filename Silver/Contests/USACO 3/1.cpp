// USACO 2026 Third Contest, Silver
// Problem 1. Clash!

// this problem just took me WAYYY too long. the implementation itself was so 
// confusing and then i didnt realize a cost could be repeated. oh well either way
// my code is so messy and not great at all and i wasted so much time just trying
// to implement and debug this problem

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, H;
    cin >> N >> H;
    vector<pair<int,bool>> orig(N); // cost, win/not
    for (int i{0}; i < N; ++i) {
        int a; cin >> a;
        orig[i] = {a,false};
    }
    int k; cin >> k;
    for (int i{0}; i < k; ++i) {
        int idx; cin >> idx; idx--;
        orig[idx].second = true;
    }
    queue<pair<int,bool>> cost; // cost, win/not
    for (int i{0}; i < N; ++i) {
        cost.push(orig[i]);
    }

    priority_queue<int> hand{};
    priority_queue<int> winHand{};
    for (int i{0}; i < H; ++i) {
        int a = cost.front().first;
        bool win = cost.front().second;
        cost.pop();
        if (win) winHand.push(-1*a);
        else hand.push(-1*a);
    }

    long long start = -1, add = 0, T = 0LL;
    vector<pair<int,bool>> order{};    // N-H+1
    int idx = 0;
    while (order.size() < N-H+1) {
        // play a card
        int a = -1;
        bool win = false;
        if (!winHand.empty()) {
            win = true;
            a = -1*winHand.top();
            winHand.pop();
            T += (long long)a;
            if (start == -1) {
                start = T;
                idx = order.size();
            }
        } else {
            a = -1*hand.top();
            hand.pop();
            T += (long long)a;
        } order.push_back({a,win});
        cost.push({a,win});

        // draw the top card
        a = cost.front().first;
        win = cost.front().second;
        cost.pop();
        if (win) winHand.push(-1*a);
        else hand.push(-1*a);
    }

    long long cnt = 0LL, incSum = 0LL;
    vector<long long> inc{};
    int i = (idx+1)%(int)order.size();
    for (int j{0}; j < order.size(); ++j) {
        int a = order[i].first;
        bool win = order[i].second;
        cnt += (long long)a;
        if (win) {
            inc.push_back(cnt);
            incSum += cnt;
            cnt = 0LL;
        } i=(i+1)%(int)order.size();
    }

    vector<long long> rem{};
    for (int i{0}; i < inc.size()-1; i++) {
        rem.push_back((long long)inc[i]);
        if (i>0) rem[i] += rem[i-1];
    }

    int Q; cin >> Q;
    while (Q--) {
        long long t; cin >> t;

        long long sz = inc.size();
        long long ans = sz*((t-start)/incSum) + 1LL;
        if (t < start) ans = 0LL;
        else {
            long long r = (t-start) % incSum;
            int i = upper_bound(rem.begin(), rem.end(), r) - rem.begin();
            i--;
            if (i >= 0) ans += (long long)i+1;
        }
        
        cout << ans << endl;
    }
}
