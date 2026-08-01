// C

// yaya i didnt actually know if this would tle or not :)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; string S; cin >> N >> S;

    vector<int> pref(N+1,0);
    for (int i=1; i < N; i++) {
        pref[i] = pref[i-1]+(S[i-1]=='o'? 1 : 0);
    }

    for (int i=0; i < N; i++) {
        int pos = i, prev_pos = i, hits = pref[i+1];
        while (pos < N && hits > 0) {
            pos += hits;
            if (pos < N) hits = pref[pos+1] - pref[prev_pos+1];
            prev_pos = pos;
        }
        if (pos>=N) pos = N-1;
        cout << pos+1 << '\n';
    }
}