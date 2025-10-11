// CF - C. Vasya and String - R1500 - 09/23/2025

// Start: 10:32 
// End: 10:51       19 mins

// OMG this was so easy i honestly needed this so bad after the problems ive been solving recently. its prob bc
// this is a problem from uh... 9 years ago heh but hey i didn't even see it

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    string s;
    cin >> N >> K >> s;

    int ans = 0;
    int curr_ans = 0;
    int curr_replace = 0;
    int l = 0, r = 0;
    while (l < N && r < N) {
        if (s[r] == 'a') {
            curr_ans++;
            r++;
        } else if (curr_replace < K) {  // s[r] == 'b'
            curr_replace++;
            r++;
        } else {
            if (s[l] == 'a') curr_ans--;
            else curr_replace--;
            l++;
        }
        ans = max(ans, curr_ans + curr_replace);
    }

    l = 0; r = 0; curr_ans = 0; curr_replace = 0;
    while (l < N && r < N) {
        if (s[r] == 'b') {
            curr_ans++;
            r++;
        } else if (curr_replace < K) {  // s[r] == 'a'
            curr_replace++;
            r++;
        } else {
            if (s[l] == 'b') curr_ans--;
            else curr_replace--;
            l++;
        }
        ans = max(ans, curr_ans + curr_replace);
    }
    
    cout << ans << endl;
}
