// B

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; string S; cin >> N >> S;

    int ans = 0;
    for (int i=0; i < N; i++) {
        if (S[i] == 'x' && (i==0 || S[i-1]=='x') && (i==N-1 || S[i+1]=='x')) ans++;
    } cout << ans << '\n';
}