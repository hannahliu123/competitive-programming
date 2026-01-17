// E

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<int> pref(N+1, 0);
    for (int i{0}; i < N; ++i) {
        int x = 0;
        if (S[i] == 'A') x = 1;
        else if (S[i] == 'B') x = -1;
        pref[i+1] = pref[i]+x;
    }
    
    map<int, int> cnt;  // value = how many times the key appears in pref
    for (int i{0}; i <= N; ++i) {
        cnt[pref[i]]++;
    }

    long long ans = 0;
    for (int i{0}; i < N; ++i) {
        // find how many items after are > pref[i]
        cnt[pref[i]]--;
        for (auto& m : cnt) {
            if (m.first > pref[i]) ans += m.second;
        }
    }

    cout << ans << endl;
}
