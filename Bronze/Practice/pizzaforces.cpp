// CF - 1555A (Brute Force)

// Start: 2:05
// End: 3:30

// It's kinda embarrassing how long that took... but uh at least I figured it out
// on my own... so uh the part I fixed was adding if N was equal to 9. It also
// took me a really long time to even pick a startegy and implement it. I didn't
// really have a super clear idea before I went in and starting typing stuff. I
// was just making stuff along the way, which ig is why it took me so long to 
// finish this problem. Erm longer log in google docs

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        long long ans = 1000000000000000000;
        long long L = (N >= 10? N/10 : 0);
        long long M = ((N-L*10) >= 7? 1 : 0);
        long long S = (N-L*10-M*8 > 0? 1 : 0);
        if (N == 9) {
            L = 1;
            M = 0;
            S = 0;
        }
        ans = min(ans, L*25 + M*20 + S*15);
        if (L) {
            --L; 
            ++M;
            if (L*10 + M*8 + S*6 >= N) ans = min(ans, L*25 + M*20 + S*15);
        } if (M) {
            --M; ++S;
            if (L*10 + M*8 + S*6 >= N) ans = min(ans, L*25 + M*20 + S*15);
        } cout << ans << '\n';
    }
}
