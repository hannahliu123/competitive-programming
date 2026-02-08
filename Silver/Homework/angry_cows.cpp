// D - Angry Cows

// Start: 1:20
// End: 1:37        17 mins

// yippeeee i cooked

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int N, K; cin >> N >> K;
    vector<int> x(N);
    for (auto& i : x) cin >> i;

    sort(x.begin(), x.end());
    int l = 0, r = 500000000;
    while (l != r) {
        int mid = (l+r)/2;
        int cows = 0, until = -1;
        for (auto& i : x) {
            if (until < i) {
                cows++;
                until = i+2*mid;
            }
        }
        if (cows <= K) r = mid;
        else l = mid+1;
    }

    cout << l << endl;
}
