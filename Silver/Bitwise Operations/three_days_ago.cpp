// AtCoder - D - Three Days Ago

// In this problem, we are looking for the subarrays where there are an even number
// of all characters. We are aiming for a O(N) time complexity, so we can't naively
// try all subarrays. Thus, we want a way where we can loop through the subarray one
// time and for each index i, we should know how many other indexes j can be selected
// to satisfy the condition. To acheive this, we know that there are only 10 possible
// value options (0-9), so we can keep count of the number of each value we've seen
// as a prefix of the string. Then, we can represent all values 0-9 as a 10-bit number
// where each position corresponds to whether we've seen either an even or odd number
// of that value. Then, the problem is simplefied down to for each index of the prefixes
// how many other indexes have the exact same distribution (or decimal value). 

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int N = s.length();
    vector<int> pref(N+1, 0);   // pref[i] = even distribution of 0-9 up to s[i-1]

    for (int i=0; i < 10; i++) {
        pref[0] |= (1<<i);    // set all pref[0] bits to 1 (all even b/c there are none of any value)
        for (int j=0; j < N; j++) {
            int x = s[j] - '0';
            if (x==i) { // make bit different from pref[j]
                // previously bit was off
                if (!(pref[j] & (1<<i))) pref[j+1] |= (1<<i);
            } else {  // keep the bit the same as it was in pref[j]
                if (pref[j] & (1<<i)) pref[j+1] |= (1<<i);
            }
        }
    }

    map<int,int> cnt{};
    long long ans = 0;
    for (auto& i : pref) cnt[i]++;
    for (auto& p : cnt) {
        ans += ((long long)p.second)*(p.second-1)/2;
    }

    cout << ans << endl;
}
