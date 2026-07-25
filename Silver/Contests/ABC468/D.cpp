// D

// for this problem u just needed to know what order to process substrings in. the optimal
// order is to process them by middle then continuing to expand the substring to the left
// and right. this way, you only need O(1) time to check if the new substring is good.
// beacuse the bounds are small, we can directly simulate every possible substring

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int N = s.length();

    int ans = 0;
    for (int i=0; i < N; i++) {
        ans++;  // i in the middle
        int mistakes = 0;
        int l=i-1, r=i+1;
        while (l>=0 && r<N && mistakes <= 1) {
            if (s[l] != s[r]) mistakes++;
            if (mistakes <= 1) {
                ans++; l--; r++;
            }
        }
        
        // i & i-1 in the middle
        l=i-1; r=i; mistakes = 0;
        while (l>=0 && r<N && mistakes <= 1) {
            if (s[l] != s[r]) mistakes++;
            if (mistakes <= 1) {
                ans++; l--; r++;
            }
        }
    }

    cout << ans << '\n';
}