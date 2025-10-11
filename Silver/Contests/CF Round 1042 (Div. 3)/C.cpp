// Problem C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        long long K;
        cin >> N >> K;

        vector<pair<int,int>> S;
        for (int i{0}; i < N; ++i) {
            long long x;
            cin >> x;
            long long multiply = x/K;
            long long pos = x - (K*multiply);
            long long neg = abs(x - (K*(multiply + 1)));
            S.push_back({min(pos, neg), max(pos, neg)});
        }

        vector<pair<int,int>> T;
        for (int i{0}; i < N; ++i) {
            long long x;
            cin >> x;
            long long multiply = x/K;
            long long pos = x - (K*multiply);
            long long neg = abs(x - (K*(multiply + 1)));
            T.push_back({min(pos, neg), max(pos, neg)});
        }

        sort(S.begin(), S.end());
        sort(T.begin(), T.end());

        if (S == T) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
