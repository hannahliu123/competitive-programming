// CF - C. Product of Three Numbers - R1300

// Start: 8:10
// End: 8:27        17 mins yessir first try lets gooooo

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        int divisor = 2;
        vector<int> ans{};
        bool possible = true;
        while (N > 1) {
            if (N % divisor == 0 && divisor < N) {
                N /= divisor;
                ans.push_back(divisor);
                if (ans.size() == 2) {
                    if (N == ans[0] || N == ans[1]) possible = false;
                    else ans.push_back(N);
                    break;
                }
            } else if (divisor > N / divisor) {
                possible = false;
                break;
            } divisor++;
        }

        if (possible) {
            cout << "YES\n";
            cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
        } else cout << "NO\n";
    }
}
