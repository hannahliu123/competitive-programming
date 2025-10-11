// CF - D. Counting Pairs - R1200

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        ll x, y;
        cin >> N >> x >> y;

        vector<ll> a(N);
        for (auto& i : a) cin >> i;
        sort(a.begin(), a.end());       // least -> greatest

        ll pairs{0};
        ll sum = accumulate(a.begin(), a.end(), 0LL);
        ll min_pair = max(0LL, sum-y), max_pair = sum-x;

        if (max_pair < 2) {         // impossible
            cout << 0 << '\n';
            continue;
        }
        
        ll right = N-1, left = N-1;
        for (int i{0}; i < N; ++i) {
            if (right <= i) break;
            left = max(left, i+1LL);
            while (a[right]+a[i] > max_pair && right > i+1) {
                right--;
            } while (a[left-1]+a[i] >= min_pair && left > i+1) {
                left--;
            } if (left <= right && a[right]+a[i] >= min_pair && a[right]+a[i] <= max_pair) {
                pairs += right - left + 1;
            }
        }

        cout << pairs << '\n';
    }
}
