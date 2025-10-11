// CF - D. Permutation Game - R1400

// Start: 7:37
// End: 8:05        28 mins

// YUHHH FIRST TRY SLAY THE DAY AWAY. kinda annoyed tho cos this is suppoused to
// be a graph problem but like i never use a graph algorithm for graph problems...

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, K, b, s;
        cin >> N >> K >> b >> s;
        b--; s--;

        vector<int> a(N);
        for (auto& i : a) cin >> i;
        vector<long long> points(N);
        for (auto& i : points) cin >> i;

        long long curr_b{points[b]}, curr_s{points[s]};
        long long b_score{points[b]*K}, s_score{points[s]*K};
        // calculate Bodya & Sasha max
        for (int i{1}; i < min(K, N); ++i) {
            // try each next value & add max of staying there for the rest
            b = a[b]; b--;
            long long temp_b = curr_b + (K-i)*points[b];
            b_score = max(b_score, temp_b);
            curr_b += points[b];

            s = a[s]; s--;
            long long temp_s = curr_s + (K-i)*points[s];
            s_score = max(s_score, temp_s);
            curr_s += points[s];
        }

        if (b_score > s_score) cout << "Bodya" << endl;
        else if (s_score > b_score) cout << "Sasha" << endl;
        else cout << "Draw" << endl;
    }
}
