// A - Foreign Exchange

// Start: 11:25
// End: 11:34       9 mins

// k this was easy peasy but i lowkey got it wrong at first lol cos i didn't
// account for if a similar student a,b was inserted multiple times

#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int N; cin >> N;
        if (N==0) return 0;

        map<pair<int,int>, int> s;
        for (int i{0}; i < N; ++i) {
            int a, b;
            cin >> a >> b;
            if (s[{b,a}] > 0) s[{b,a}]--;
            else s[{a,b}]++;
        }

        int pos = true;
        for (auto& i : s) {
            if (i.second > 0) {
                pos = false;
                break;
            }
        }

        cout << (pos? "YES" : "NO") << endl;
    }
}
