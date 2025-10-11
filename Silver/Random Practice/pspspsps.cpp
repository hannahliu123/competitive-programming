// CF - B. pspspsps - R1300

// Start: 1:19
// End: 2:43        1 hr 24 mins

// Took so long cos i was trying to find a pattern and i even tryied implementing that
// "pattern" solution but i realized halfway how stupid it was...

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N; 
        string s;
        cin >> N >> s;

        // vector<int> used(N);    // how many times each number has been used
        vector<int> p(N, -1);    // final permutation

        // Fill all 's'
        int next{0}, last_s{N};
        for (int i{N-1}; i >= 0; --i) {
            if (s[i] == 's') {
                for (int j{i}; j < last_s; ++j) {
                    // used[next]++;
                    p[j] = next++;
                } last_s = i;
            }
        }

        // Fill all remaining numbers
        for (int i{0}; i < N; ++i) {
            if (p[i] == -1) {
                p[i] = next++;
            }
        }

        // Check
        int last_p{-1};
        bool possible{true};
        for (int i{0}; i < N; ++i) {
            if (s[i] == 'p') {
                for (int j{last_p+1}; j <= i; ++j) {
                    if (p[j] > i) {
                        possible = false;
                        break;
                    }
                }

                last_p = i;
                if (!possible) break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
}
