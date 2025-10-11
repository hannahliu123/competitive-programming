// USACO 2022 January Contest, Bronze
// Problem 3. Drought

// Start: 7:12
// End: 9:22        i give up       2 hrs 10 mins :(

// alrightly lets uh see what the frickity frack i messed up, and istg if i 
// misunderstood question again im gonna explode. 

// OMG SO MY IDEA WORKED PERFECTLY AND PASSED ALL TEST CASES THE AFTER I FIGURED OUT
// THE MISTAKE. Only sad part is that I had to use the solution test cases to actually
// figure it out. This means I need to get better at torubleshooting and debugging.
// I was pretty confident that my idea worked, but that tiny bit of uncertainty led me
// to just give up. If I wrote my code on paper neater (with the exact position of
// where to check if everything was equal), then I might've been able to catch my
// mistake. I still think I wouldn't though, which is really unfortunate. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> h(N);
        for (int i{0}; i < N; ++i) cin >> h[i];

        long long ans{0};     // min bags of corn
        int sub{0};
        if (N == 2) {
            if (h[0] == h[1]) ans = 0;
            else ans = -1;
        } else {
            while (true) {
                bool allequal = true;
                bool impossible = true; // false if next item is lower
                for (int i{1}; i < N-1; ++i) {
                    if (h[0]!=h[1] || h[i]!=h[i-1] || h[i]!=h[i+1]) allequal = false;
                    if (h[i+1]>=0 && h[i]>h[i+1]) {
                        impossible = false;
                        sub = h[i]-h[i+1];
                        h[i] -= sub;
                        h[i-1] -= sub;
                        ans += 2*sub;
                    } if (h[i-1]>=0 && h[i]>h[i-1]) {
                        impossible = false;
                        sub = h[i]-h[i-1];
                        h[i] -= sub;
                        h[i+1] -= sub;
                        ans += 2*sub;
                    } if (h[i-1]<0 || h[i]<0 || h[i+1]<0) {
                        impossible = true;
                        break;
                    }
                } if (allequal) break;
                if (impossible) {
                    ans = -1; 
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
}
