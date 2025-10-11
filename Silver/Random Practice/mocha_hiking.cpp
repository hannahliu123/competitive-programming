// CF - C. Mocha and Hiking - R1200

// Start: 2:49
// End: 3:16        27 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> a(N);
        for (auto& i : a) cin >> i;
    
        vector<int> order{};
        bool done = false;
        for (int i{0}; i < N; ++i) {    // insert N+1 somewhere if possible
            if (i == 0 && a[i] == 1) {      // add to start
                order.push_back(N+1);
                done = true;
            } else if (!done) {
                if (a[i] == 1 && a[i-1] == 0) {
                    order.push_back(N+1);
                    done = true;
                }
            }

            order.push_back(i+1);
        }

        if (!done && a[N-1] == 0) {     // add to end
            order.push_back(N+1);
        } 

        if (order.size() == N+1) for (int i : order) cout << i << ' ';
        else cout << -1;
        cout << '\n';
    }
}
