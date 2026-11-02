#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int B, L, E; cin >> B >> L >> E;
        int start = (B+E)%50, end = L;
        if (start>end) cout << "0\n";
        else cout << (end-start)/50 + 1 << '\n';
    }
}