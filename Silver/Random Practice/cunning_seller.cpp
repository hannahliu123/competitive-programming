// CF - C2. The Cunning Seller (hard version) - R1400

// Start: 5:57
// End: 7:04        1 hr 7 mins (i kindaish got distracted tho so a little less than an hour)

// So i just did a ton of greedy-ish math code which kinda juts trial-and-errors through
// everything. lemme see if theres a better solution or implementation
// OHHHH editorial is the same logic as meeee!

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    vector<long long> price(19, 3);
    for (int i{1}; i < 19; ++i) price[i] = pow(3,i+1) + i*pow(3,i-1);

    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> powers(19, 0); // how many times each power from 0-18 is used 
        for (int i{18}; i >= 0; --i) {
            int x = N/(pow(3,i));
            powers[i] = x;
            N -= x*pow(3,i);
        }

        int deals = accumulate(powers.begin(), powers.end(), 0);
        if (deals > K) {
            cout << -1 << '\n';
            continue;
        }

        for (int i{18}; i > 0; --i) {
            if (powers[i] == 0) continue;

            int convert = (K-deals)/2;
            if (powers[i] < convert) {
                deals += 2*powers[i];
                powers[i-1] += 3*powers[i];
                powers[i] = 0;
            } else {
                deals += 2*convert;
                powers[i-1] += 3*convert;
                powers[i] -= convert;
                break;
            }
        }

        long long ans = 0;
        for (int i{0}; i <= 18; ++i) {
            ans += powers[i]*price[i];
        }

        cout << ans << endl;
    }
}
