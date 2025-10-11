// CF - 1327B - R1200 - Princesses and Princes

// Okay so this worked, then it like didn't work?? but like i didn't rly change any of
// my ideas????? so uh ill take it tho. Lets... uh read hte editorial. Ok so it's the
// same idea but simpler-ish. Hey ill take it cos i got the right idea. its the thought
// that counts! Time to do a USACO problem!!!!!

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("princess.in", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<bool> princes(n);
        int princess{1000000000};
        for (int i{0}; i < n; ++i) {
            int k;
            cin >> k;
            bool couple{false};
            for (int j{0}; j < k; ++j) {
                int prince;
                cin >> prince;
                if (!princes[prince-1] && !couple) {
                    princes[prince-1] = true;
                    couple = true;
                } else if (j == k-1 && !couple) princess = i+1;
            } if (k == 0) princess = min(princess, i+1);
        }

        if (princess == 1000000000) {
            for (int i{0}; i < n; ++i) {
                if (!princes[i]) {
                    cout << "IMPROVE\n";
                    cout << princess << ' ' << i+1 << '\n';
                    break;
                }
            } cout << "OPTIMAL\n";
        } else {
            cout << "IMPROVE\n";
            for (int i{0}; i < n; ++i) {
                if (!princes[i]) {
                    cout << princess << ' ' << i+1 << '\n';
                    break;
                }
            }
        }
    }
}
