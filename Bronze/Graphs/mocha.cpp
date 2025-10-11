// CF - 1559C - R1200 - Mocha and Hiking

// I had the right idea at first, the answer key just kinda reordered it. Uh I don't 
// think I would've been able to firgure this one out, simply because the logic/
// "patterns" are too complicated. I think I need to practice easier questions because 
// this was too hard. Maybe it's cos i haven't learned constructive algorithms before.

// OH OKAY! If nothing works then I need to step back and examine how the example
// problems got their answer. Notice that in each of them it goes in increasing order
// (1, 2, 3, 4..) except for ONE number inserted somewhere (n+1). After I took note of
// that, I could've realized I just need to find a place to insert the last number
// (n+1). I would've then been able to look for that specifically in the test cases I 
// drew out. i dont really wanna do this rn, so i might finish this problem later. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;  // number of villages = n+1
        cin >> n;

        vector<int> roads(n+1);
        for (int i{1}; i <= n; ++i) {cin >> roads[i];}

        if (roads[1]==1) {
            cout << n+1 << ' ';
            for (int i{1}; i <= n; ++i) cout << i << ' ';
            cout << '\n';
        } else if (roads[n]==0) {
            for (int i{1}; i <= n+1; ++i) cout << i << ' ';
            cout << '\n';
        } else {
            // okay yeah I don't understand this
        }
    }
}
