// okay so i realized you can basically rearrange indexes of the same parity in any way
// you want, and obviously the peak of the curve has to be the largest number (N). okay
// for this problem i should've just kept playing around with different representations
// ig. one key invariant (smthing that's true and never changes) for a working solution
// is that if the value N is at an even index, N-1 must be right next to it to the left
// or right (so an odd index in this case). Then N-2 must be right next to that block
// to the left or right (this time could be even or odd). Same for N-3 and so on. So,
// starting from the very end, we just need to make sure we there next number can be
// placed in its appropriate parity index. if so, there's a solution. if not, no solution

// BRUHHHH this solution is so simple omg sdjhfldsjflksadjfl i just had to find that 
// invariant and also maybe try evaluating the problem backwards (so like given a working
// solution, how could we move the values around to create the original problem). this is
// literally just like procressing backwards (kinda right to left ksjdflsjfkdslj)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        vector<int> loc(N+1);
        for (int i=0; i < N; i++) {
            cin >> a[i];
            loc[a[i]] = i;
        }

        int l=0, r=0;
        if (loc[N]%2==0) {
            l = 1; r = 1;
        } bool pos = true;
        for (int i=N-1; i > 0; i--) {
            if (loc[i]%2==0) {
                if (l==0) {
                    l=1;
                } else if (r==0) {
                    r=1;
                } else {
                    pos = false; break;
                }
            } else {
                if (l==1) {
                    l=0;
                } else if (r==1) {
                    r=0;
                } else {
                    pos = false; break;
                }
            }
        }

        cout << (pos? "Yes" : "No") << '\n';
    }
}