// CF - C. Sakurako's Field Trip - R1400

// Start: 9:15
// End: 10:06       51 mins (but like i got really distracted and was NOT locked in)

// idk i just feel so out of it recently. this wasn't a hard problem (although my implementaion
// is quite sketchy) but like I just didn't feel like coding it out at all and i just wanna sleep
// even though it's 10am in the morning and i shouldn't feel so tireddddd. ugh this is the first
// cp problem i did this week and its sunday... (considering M-S one week lol) wtv lets upsolve

// Erm DP and two pointers where the two other tags?? i just did greedy (as always lol my love)
// whatever the cleaner implementation is just to swap if it improves the solution. i thought 
// that was like too straightforward so i went with this comparison complicated route. um but
// why does it work? yeah so we only have two options, and so if one results in fewer disturbances
// than the other, then it is more desirable. yay

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<int> a(N);
        for (auto& i : a) cin >> i;

        int l = 1;
        int r = N-2;
        vector<int> ans(N, -1);
        ans[0] = a[0];
        ans[N-1] = a[N-1];
        while (l <= r) {
            int lval = ans[l-1], rval = ans[r+1];
            int op1 = a[l], op2 = a[r];
            if (op1 == op2) {
                ans[l] = op1;
                ans[r] = op2;
            } else if (lval == op1 || lval == op2) {
                if (lval == op2) {
                    ans[l] = op1;
                    ans[r] = op2;
                } else {
                    ans[l] = op2;
                    ans[r] = op1;
                }                
            } else if (rval == op1 || rval == op2) {
                if (rval == op1) {
                    ans[l] = op1;
                    ans[r] = op2;
                } else {
                    ans[l] = op2;
                    ans[r] = op1;
                }                
            } else {
                ans[l] = op1;
                ans[r] = op2;
            } l++; r--;
        }

        int disturbances = 0;
        for (int i{0}; i < N-1; ++i) {
            if (ans[i] == ans[i+1]) disturbances++;
        }

        cout << disturbances << endl;
    }
}
