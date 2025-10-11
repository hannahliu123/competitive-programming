// CF - ABBC or BACB - 1873G - 1500?

// Start: 4:54
// End: 5:38        read the editoriallllll~

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;   // A or B
        cin >> s;

        int mnAs{1000000000}, acnt{0}, mxBs{0}, bcnt{0}, totala{0};
        for (int i{0}; i < s.size(); ++i) {
            if (s[i]=='A') {
                totala++;
                acnt++;
                mxBs = max(mxBs, bcnt);
                bcnt = 0;
            } else {
                bcnt++;
                if (acnt > 0) {
                    mnAs = min(mnAs, acnt);
                    acnt = 0;
                }
            } if (i == s.size()-1) {
                if (s[i] == 'A') mnAs = min(mnAs, acnt);
                else mxBs = max(mxBs, bcnt);
            }
        }

        int ans{totala};
        if (s[0]!='B' && s[s.size()-1]!='B' && mxBs==1) ans -= mnAs;
        else if (mxBs == 0) ans = 0;

        cout << ans << '\n';
    }
}
