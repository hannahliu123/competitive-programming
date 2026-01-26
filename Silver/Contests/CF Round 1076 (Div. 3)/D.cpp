// D

// oh ok so instaed of doing binary search you could've just kept a poitner
// that iterated through b. Instead of sorting the strength from l -> g, we 
// could've sorted from g -> l, so as we processed the stregnths, it would
// be decreasing (so x would be decreasing too) and so the number of valid 
// swords would be increasing (starting as just the strongest sword but then
// including lower stengthed swords). The number of valid swords would just
// equal i. Then we could use a pointer approach where we track the last
// valid index of the level we were able to beat. Because we get more and 
// more valid swords, we can keep increasing that level index until we no
// long can, then update the ans to be i*level. We would only visit each
// level one time and each sword one time so the time complexity is O(2N),
// which is just O(N)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> a(N);   // strength
        for (auto& i : a) cin >> i;
        vector<int> b(N);   // strikes needed
        for (auto& i : b) cin >> i;

        sort(a.begin(), a.end());   // l -> g
        vector<long long> pref(N+1, 0); // this needs to be long longs!!!
        for (int i{0}; i < N; ++i) {
            pref[i+1] = pref[i]+b[i];
        }

        long long ans = 0;
        for (int i{0}; i < N; ++i) {
            long long x = a[i];
            long long swords = N-i;   // # of valid swords
            int level = upper_bound(pref.begin(), pref.end(), swords) - pref.begin();
            level--;
            ans = max(ans, x*level);
        }

        cout << ans << endl;
    }
}
