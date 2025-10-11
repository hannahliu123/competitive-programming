// CF - Karen and Coffee - R1400

// Start: 8:41
// End: 9:16        35 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> pref(200001, 0);
    for (int i{0}; i < N; ++i) {
        int L, R;
        cin >> L >> R;
        pref[L-1]++;
        pref[R]--;
    }

    for (int i{1}; i < 200001; ++i) {
        pref[i] += pref[i-1];
    }
    
    vector<int> final(200002, 0);
    for (int i{1}; i < 200002; ++i) {
        if (pref[i-1] >= K) final[i]++;
        final[i+1] = final[i];
    }

    while (Q--) {
        int A, B;
        cin >> A >> B;
        cout << final[B]-final[A-1] << '\n';
    }
}
