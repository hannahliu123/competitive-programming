// CF - D. Good Schedule - R1700

// Start: 2:09
// End: 3:08        59 mins

// YAYYAYAYYAYYA!!!! so the key for this probelm was to process the elements backwards.
// i noticed that you could build the solution using data you already computed :)))

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        vector<int> b(N);
        for (auto& i : b) cin >> i;

        long long ans = 0;
        vector<int> apos(N+2, N);
        vector<int> bpos(N+2, N);
        vector<int> cont(N);    // contribution if continued
        for (int i=N-1; i >= 0; i--) {
            apos[a[i]]=i;
            bpos[b[i]]=i;
            int contr = min(apos[1], bpos[1]) - i;
            if (apos[1] == bpos[1] && apos[1] < N) contr += cont[apos[1]];
            if (a[i] == b[i]) {
                int pos1 = apos[a[i]+1];
                int pos2 = bpos[a[i]+1];
                if (pos1 == pos2 && pos1 < N) {
                    cont[i] = pos1 - i + cont[pos1];
                } else {
                    cont[i] = min(pos1, pos2) - i;
                }
                if (a[i]==1) contr = cont[i];
            }
            ans += contr;
        }

        cout << ans << endl;
    }
}