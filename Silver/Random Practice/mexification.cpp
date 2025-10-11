// CF - E. Mexification - R1500

// Start: 9:22
// End: 10:59       1 hr 37 mins

// This is one of the problems where i wish i organized everything much better. My work
// was really messy, so my train of though was misled. I was spending so much time on a
// solution that didn't even work, but im glad i figured it out and didnt give up :)
// I don't honestly think R1500 was that bad, because if i were more focused i think i 
// could've solved this more quickly. the impelementation wasn't that bad and there weren't
// any super complex algorithms or logic. all and all, i think this was just okay

// Yeah and the editorial logic is very similar (basically the same) except its more neat
// and organized. the key insights are the same, being that there are many cases you need 
// to account for

// I kinda struggle with these problems if im not locked in simply because of how many edge
// cases there are

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> a(N+1, 0);
        for (int i{0}; i < N; ++i) {
            int x;
            cin >> x;
            a[x]++;
        }

        // mex is the mex of starting array, mex2 is mex after all permanent elements
        long long mex = -1, mex2 = -1;
        for (int i{0}; i <= N; ++i) {
            if (a[i] == 0) {
                if (mex == -1) mex = i;
                if (mex2 == -1) mex2 = i+1;
                break;
            } else if (a[i] > 1) {
                if (mex2 == -1) mex2 = i;
            }
        }

        long long ans = 0;
        if (K == 1) {   // take care of this case
            for (int i{0}; i <= N; ++i) {
                if (a[i] == 1 && i < mex) {     // permanent
                    ans += i;
                } else if (a[i] > 0) ans += a[i]*mex;
            }
            cout << ans << endl;
            continue;
        }

        int num_np = 0;
        for (int i{0}; i <= N; ++i) {
            if (a[i] == 1 && i < mex2) {     // permanent
                ans += i;
            } else if (a[i] > 0) num_np += a[i];
        }

        if (num_np == 1) {
            ans += mex;
        } else if (mex < mex2) {   // mex2 = mex + 1
            if (K % 2 == 0) ans += mex2*num_np;   // even (mex2)
            else ans += mex*num_np;               // odd (mex)
        } else {
            if (K % 2 == 0) ans += mex2*num_np;   // even (mex2)
            else ans += (mex2+1)*num_np;          // odd (mex2+1)
        }

        cout << ans << endl;
    }
}
