// Problem D

#include <bits/stdc++.h>
using namespace std;

vector<int> values;
vector<int> reals;
vector<vector<int>> casino;
int N;

void setVal(int i, int val) {
    values[i] = val;

    int index = lower_bound(reals.begin(), reals.end(), casino[i][1]) - reals.begin();
    if (index < 0 || index >= N) return;
    for (int j{index}; j < N; j++) {
        if (reals[j] >= casino[i][1] && reals[j] <= casino[i][2] && values[j] == -1) setVal(j, val);
        else break;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int K;
        cin >> N >> K;

        casino.clear();
        casino.resize(N);
        values.clear();
        values.resize(N, -1);
        for (int i{0}; i < N; ++i) {
            int l, r, v;
            cin >> l >> r >> v;
            bool reachable = false;
            if (K >= l && K <= r) reachable = true;
            casino[i] = {v, l, r, reachable};
        }

        sort(casino.begin(), casino.end());   // least -> greatest real
        reals.clear();
        reals.resize(N);
        for (int i{0}; i < N; ++i) {
            reals[i] = casino[i][0];
        }
        
        int coins = K;
        for (int i{N-1}; i >= 0; --i) {
            if (values[i] == -1) {
                setVal(i, casino[i][0]);
            }

            if (casino[i][3]) coins = max(coins, values[i]);
        }

        cout << coins << endl;
    }
}
