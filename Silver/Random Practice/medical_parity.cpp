// CF - M. Medical Parity - R1700

// Start: 1:05
// End: 1:33        28 mins

// yayay this was pretty much just a greedy problem and i really like greedy problems
// :). i thought it might be bitwise at first and i got scared but nah it wasnt. oh
// wow the editorial uses dynamic programming but this solution is so much simpler. ig
// the proof is harder. basically i noticed that if you looked for all "issues" in the
// array respective to the previous bit, you could figure out where flips were needed.
// so like if u flip one bit in x then all bits in y after that index flips. then if u
// flip y_i, bits x_i and x_i+1 flip. using that logic its optimal to flip y whenever
// there are two or more issues in a row.

// so the dp solution would be to track the number of flips required for each index to
// end in either 0 or 1 (in y, so parity). then youd just take the minimum of the final
// even or odd ending at the last index.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string x, y; cin >> x >> y;
        int N = x.length();

        int ans = 0;
        int chain = 0;  // chain of invalids
        int prev = 0;   // prev value of y
        for (int i=0; i < N; i++) {
            int xi = x[i]-'0', yi = y[i]-'0';
            if (xi==0 && yi!=prev) {    // invalid
                chain++;
            } else if (xi==1 && yi==prev) { // invalid
                chain++;
            } else {    // valid
                ans += (chain+1)/2;
                chain = 0;
            }
            prev = yi;
        } ans += (chain+1)/2;

        cout << ans << endl;
    }
}
