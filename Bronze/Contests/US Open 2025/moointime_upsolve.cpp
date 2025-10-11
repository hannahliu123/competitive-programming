// USACO 2025 US Open Contest, Bronze
// Problem 3. It's Mooin' Time III

// My second try after learning some Silver topics and having a bit more practice

// Start: 2:23
// End: 4:03        1 hr 40 mins

// Bruh I got the autistic ASCII stuff wrong omg I could've solved it a bit eariler. I 
// had very little hope in my plan but it worked out!! I'm super happy hehe let's upsolve
// the upsolve now...

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    string s;
    cin >> N >> Q >> s;

    vector<vector<int>> letters(26);    // 0 = a, 1 = b, 2 = c...
    for (int i{0}; i < N; ++i) {
        letters[s[i]-'a'].push_back(i+1);   // 1-indexed
    }

    while (Q--) {
        int l, r;
        cin >> l >> r;

        ll ans{-1LL};
        for (int a{0}; a < 26; ++a) {
            if (letters[a].size() == 0) continue;

            // highest index of k with a value of a (as a char) within l -> r
            ll k = *(upper_bound(letters[a].begin(), letters[a].end(), r)-1);
            if (k > r || k <= l+1 || s[k-1] != (char)(a+97)) continue;

            // lowest index of any letter != a (as a char)
            ll i = l;
            if (s[l-1] == (char)(a+97)) {
                i = N;
                for (int b{0}; b < 26; ++b) {
                    if (b != a) {
                        auto it = upper_bound(letters[b].begin(), letters[b].end(), l);
                        if (it == letters[b].end()) {    // impossible
                            continue;
                        } else {
                            i = min(i, (ll)*it);
                        }
                    }
                }

                if (i+1 >= k) continue;
            }

            // determine j
            auto it_above = lower_bound(letters[a].begin(), letters[a].end(), (i+k)/2);
            auto it_below = lower_bound(letters[a].begin(), letters[a].end(), (i+k)/2)-1;
            ll j;
            if (it_above != letters[a].end()) {     // something greater than or equal to
                j = *it_above;
                if (j < k) ans = max(ans, (j-i)*(k-j));
            }
            if (it_above != letters[a].begin()) {   // something below
                j = *it_below;
                if (j > i) ans = max(ans, (j-i)*(k-j));
            }
        }

        cout << ans << endl;
    }
}
