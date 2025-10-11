// CF - C2. Skibidus and Fanum Tax (hard version) - R1300

// Start: 10:24
// End: 11:21       57 mins (HOLY MOLY BRO)

// Bro I literally submitted the SIX times in total. Today is not my lucky day omg. I guess
// I need a lot more practice with binary search and two pointers because I keep forgetting
// little deatails! And also i always have some kinda of out of bounds error the first times
// whether it's long longs or indexing :(. Okay actuallllly my conditionals work pretty well
// and are overall kind of similar to the editorial. I mean it makes sense to me, so I guess
// it's fiiiiiiiiine

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<long long> a(N);
        for (auto& i : a) cin >> i;
        vector<long long> b(M);
        for (auto& i : b) cin >> i;
        sort(b.begin(), b.end());

        bool possible = true;
        if (b[0] < 2*a[0]) a[0] = b[0] - a[0];
        for (int i{1}; i < N; ++i) {
            long long lower = a[i]+a[i-1];
            int index = lower_bound(b.begin(), b.end(), lower) - b.begin();
            if (index >= 0 && index < M && b[index] >= lower) {
                if (a[i] < a[i-1] && b[index] - a[i] > a[i]) {
                    a[i] = b[index] - a[i];
                } else if (a[i] > a[i-1] && b[index] - a[i] < a[i]) {
                    a[i] = b[index] - a[i];
                }
            }
            
            if (a[i] < a[i-1]) {
                possible = false;
                break;
            }
        }

        cout << (possible? "YES\n" : "NO\n");
    }
}
