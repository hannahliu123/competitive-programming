// Hoof Paper Scissors Minus 1

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;   // number of hoof symbols and number of games
    cin >> N >> M;

    vector<int> loses[N];
    for (int i{0}; i < N; ++i) {
        for (int j{0}; j <= i; ++j) {
            char c;
            cin >> c;
            if (c == 'W') {
                loses[j].push_back(i);
            } else if (c == 'L') {
                loses[i].push_back(j);
            }
        }
    } for (int i{0}; i < M; ++i) {
        int e1, e2;
        cin >> e1 >> e2;

        --e1; --e2;
        set<int> options{};
        if (loses[e1].size() > 0 && loses[e2].size() > 0) {
            for (int x : loses[e1]) {
                for (int y : loses[e2]) {
                    if (x == y) options.insert(x);
                }
            }
        }
        
        int ans = 0;
        int op = options.size();
        if (op > 0) {
            ans = op*(2*(N-op)+1)+(op*(op-1));
        }

        cout << ans << '\n';
    }
}
