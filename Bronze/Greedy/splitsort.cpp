// CF - 1863B, R1100

// This was so reaally good idea, and im super proud of this solution because I
// took this time to draw out and test a bunch of different ideas until I
// landed on one that worked (this solution). When i saw i didn't satisfy the
// time constraints, I was able to make a solution (in splitsort2.cpp) that
// used a similar idea (basically the same) but a different, faster 
// implementation. Yippeeeee!!!!

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i{0}; i < n; ++i) {cin >> p[i];}

        set<int> seen;
        int chain{0};
        for (int i{0}; i < n-1; ++i) {
            if (!seen.count(p[i])) {
                int onemore{p[i]+1};
                for (int j{i+1}; j < n; ++j) {
                    if (p[j] == onemore) {
                        ++onemore;
                        ++chain;
                        seen.insert(p[j]);
                    }
                }
            }
        }

        cout << n-1-chain << '\n';
    }
}
