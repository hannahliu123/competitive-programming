// USACO 2015 December Contest, Gold
// Problem 1. High Card Low Card (Gold)

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> elsie1{};    // first half
    vector<int> elsie2{};    // second half
    vector<bool> cards(N*2+1, false);     // true of owned by elsie
    for (int i{0}; i < N; ++i) {
        int card;
        cin >> card;
        if (i < N/2) elsie1.push_back(card);
        else elsie2.push_back(card);
        cards[card] = true;
    }

    sort(elsie1.rbegin(), elsie1.rend());   // greatest -> least
    sort(elsie2.begin(), elsie2.end());     // least -> greatest

    vector<int> bessie1{};      // least -> greatest
    vector<int> bessie2{};
    for (int i{1}; i <= N*2; ++i) {
        if (!cards[i]) {
            if (bessie2.size() < N/2) bessie2.push_back(i);
            else bessie1.push_back(i);
        }
    }

    int points{0};
    int hi{N/2-1};      // bessie's highest card index
    int lo{0};          // bessie's lowest card index
    for (int i{0}; i < N/2; ++i) {      // first half - want highest card possible
        if (bessie1[hi] > elsie1[i]) {
            points++;
            hi--;
        } else lo++;
    }
    
    lo = 0;          // bessie's lowest card index
    hi = N/2-1;      // bessie's highest card index
    for (int i{0}; i < N/2; ++i) {   // second half - want lowest card possible
        if (bessie2[lo] < elsie2[i]) {
            points++;
            lo++;
        } else hi--;
    }

    cout << points << endl;
}
