// CF - B. Inflation - R1300

// Start: 8:49
// End: 9:35        46 mins I HATE LONG LONGS!!!!!!!!

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> p(N);
        for (auto& i : p) cin >> i;

        long long sum = (long long)p[0];
        long long ans = 0LL;
        for (int i{1}; i < N; ++i) {
            long double x = (long double)(((long long)p[i]*100LL)/(long double)(sum));
            if (x > K) {
                long long target = p[i]*100LL/K;
                if ((long long)(p[i]*100LL)%K != 0) target++;
                ans += (target - sum);
                sum += (target - sum);                
            } sum += p[i];
        }

        cout << ans << endl;
    }
}
