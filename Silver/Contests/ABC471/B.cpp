// B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    map<string,int> cnt;
    int ans = 0;
    for (int i=0; i < N; i++) {
        string s; cin >> s;
        for (auto& c : s) {
            c = tolower(static_cast<unsigned char>(c));
        }
        cnt[s]++;
        ans = max(ans, cnt[s]);
    }

    cout << ans << '\n';
}