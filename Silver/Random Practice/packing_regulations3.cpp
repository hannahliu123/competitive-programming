// AtCoder Beginner Contest 214 - E - Packing Under Range Regulations UPSOLVE

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N; 
        cin >> N;

        vector<pair<int, int>> balls(N);
        for (auto& b : balls) cin >> b.first >> b.second;

        sort(balls.begin(), balls.end());   // sort normally

        bool possible{true};
        int i{0}, curr{balls[0].first}, used{0};
        priority_queue<int> R{};        // use highest value of R -> R.top()
        while (used < N) {
            // Add all values at curr to 'R'
            for (int j{i}; j < N; ++j) {
                if (balls[j].first == curr) {
                    R.push(-1*balls[j].second);
                    i++;
                }
                else break;
            }

            if (R.empty()) {    // jump to the next L value/position
                curr = max(curr+1, balls[i].first);
            } else {
                if (curr <= -1*R.top()) {      // fits
                    R.pop();
                    curr++;
                } else {
                    possible = false;
                    break;
                }
            }
        }

        cout << (possible? "Yes\n" : "No\n");
    }
}
