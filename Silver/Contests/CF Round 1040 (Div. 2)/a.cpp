// Problem A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<int> s(N);
        int zeroes = 0;
        for (int i{0}; i < N; ++i) {
            cin >> s[i];
            if (s[i] == 0) zeroes++;
        }

        int score = accumulate(s.begin(), s.end(), zeroes);

        cout << score << endl;
    }
}
