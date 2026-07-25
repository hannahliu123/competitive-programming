// D

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