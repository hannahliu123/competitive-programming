// CF - A. Bear and Poker - R1300

// Start: 11:53
// End: 12:25       32 mins

// only cos i got distracted for a bit

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (auto& i : a) cin >> i;

    sort(a.begin(), a.end());
    for (int i{0}; i < N; ++i) {
        while (a[i] % 2 == 0) a[i] /= 2;
        while (a[i] % 3 == 0) a[i] /= 3;
    }

    bool possible = true;
    for (int i{0}; i < N-1; ++i) {
        if (a[i] != a[i+1]) {
            possible = false;
            break;
        }
    }

    cout << (possible? "Yes" : "No") << endl;
}
