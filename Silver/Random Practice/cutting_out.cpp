// CF - D. Cutting Out - R1600

// Start: 11:22
// End: 12:21       basically 1 hr but i spent ~15 mins debugging

// Bruh i got a stupid runtime error cos i didnt initialize the index variable
// at the very end :( This problem wasn't even hard esp cos it was from 7 yrs
// ago but i didn't start off very strong cos i thought there was suppoused to
// be a super easy and straightforward solution which (surprise surpise) was 
// wrong. I bet there is a WAY better implementation so imma check the editorial
// now.

// Okay so binary search was the editorial solution so im glad i didn't waste
// time searching for greedy solutions (which im quite fond of lol). the only
// difference is the implementation.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> freq(200000);
    for (int i{0}; i < 200000; ++i) {
        freq[i].second = i+1;
    } for (int i{0}; i < N; ++i) {
        int x;
        cin >> x;
        freq[x-1].first++;
    }

    sort(freq.rbegin(), freq.rend());   // greatest to least

    int hi = N, lo = 1;
    while (hi > lo) {
        int copies = (hi + lo + 1) / 2; // rounds up

        int k = 0;
        for (int i{0}; i < K; ++i) {
            if (freq[i].first < copies || k >= K) break;
            k += freq[i].first/copies;
        }

        if (k >= K) {
            lo = copies;
        } else hi = copies - 1;
    }

    // make lo or hi copies (should be equal)
    int index = 0, cnt = 0;
    while (cnt < K) {
        freq[index].first -= lo;
        if (freq[index].first >= 0) {
            cout << freq[index].second << ' ';
            cnt++;
        } else index++;
    } cout << endl;
}
