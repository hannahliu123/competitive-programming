// CF - C. Boring Day - R1200

// Start: 12:59
// End: 2:12        1hr 13mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, L, R;
        cin >> N >> L >> R;

        vector<long long> cards(N);
        for (auto& i : cards) cin >> i;

        long long sum{cards[0]};
        int left{0}, right{0}, wins{0};
        while (left < N && right < N) {     // make sure right doesn't accidentally pass N
            if (sum >= L && sum <= R) {     // desired range
                wins++;
                if (right != N-1) {
                    right++;
                    left = right;
                    sum = cards[right];
                } else break;
            } else if (sum < L) {       // too low
                if (right != N-1) {
                    right++;
                    sum += cards[right];
                } else break;
            } if (sum > R) {        // too high
                if (left != N-1) {
                    sum -= cards[left];
                    left++;
                    if (left > right) {
                        right = left;
                        sum += cards[right];
                    }
                } else break;
            }
        }

        cout << wins << '\n';
    }
}
