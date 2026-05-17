// CF - E. Alternating String - R1500

// Start: 7:51
// End: 9:00        1 hr 9 mins

// bruhhh my first WA was because i stopped the loop at 25 instead of 26 lol. okay but
// the reason this code took soooo long was because i had trouble with the indexing and
// implementation details. OHHH my gosh why did i not just think of using a suffix
// array!!! I could've just used the prefix even array plus a suffix odd array and
// vice versa instead of subtracting to find the suffix bruh.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N;
        string s;
        cin >> N >> s;

        vector<vector<int>> even((N+1)/2 +1, vector<int>(26, 0));
        vector<vector<int>> odd(N/2 +1, vector<int>(26, 0));
        for (int i=0; i < N; i++) {
            int idx = i/2 +1;
            int alp = s[i] - 'a';
            if (i%2==0) {
                even[idx] = even[idx-1];
                even[idx][alp]++;
            } else {
                odd[idx] = odd[idx-1];
                odd[idx][alp]++;
            }
        }

        int ans = N;
        if (N%2 == 1) {
            for (int i=0; i < N; i++) { // index to try removing
                int eIdx = i-1, oIdx = i-1; // index before curr
                if (i%2==0) eIdx--;
                else oIdx--;

                vector<int> eFreq = even[(eIdx+2)/2];
                vector<int> oFreq = odd[(oIdx+2)/2];
                if (i%2==0) eIdx += 2;
                else oIdx += 2;
                vector<int> eDel = even[(eIdx+2)/2];
                vector<int> oDel = odd[(oIdx+2)/2];

                int eMax = 0, oMax = 0;
                for (int j=0; j < 26; j++) {
                    eFreq[j] += odd[N/2][j] - oDel[j];
                    oFreq[j] += even[(N+1)/2][j] - eDel[j];

                    eMax = max(eMax, eFreq[j]);
                    oMax = max(oMax, oFreq[j]);
                }
                ans = min(ans, N-eMax-oMax);
            }
        } else {
            int eMax = 0, oMax = 0;
            for (int j=0; j < 26; j++) {
                eMax = max(eMax, even[N/2][j]);
                oMax = max(oMax, odd[N/2][j]);
            }
            ans = N-eMax-oMax;
        }

        cout << ans << endl;
    }
}
