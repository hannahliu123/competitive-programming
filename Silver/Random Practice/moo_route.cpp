// USACO 2023 January Contest, Silver
// Problem 3. Moo Route

// Start: 7:40
// Greedy Idea: 8:02
// End: 8:15                35 mins~!!

// um so apparently this was liek THE easiest silver problem in the history of usaco so 
// heh im glad i didn't sell. it was just greedy but i wasn't like super 100% confident in
// my solution cos it seemed way too simple. bro this would've the best silver contest to
// compete in ughh either way tho i would've needed to solve two problems fully and at least
// get partial credit on another

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> a(N); 
    for (auto& i : a) cin >> i;

    int i=0, finished=0;
    while (a[0]>0) {
        // right
        while (i<N && a[i]>0) {
            cout << "R";
            a[i]--; i++;
        } i--;

        // left
        while (i>=0 && (finished==N-i-1 || a[i]>2)) {
            cout << "L";
            a[i]--;
            if (a[i]==0) finished++;
            i--;
        } i++;
    } cout << '\n';
}