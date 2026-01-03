// A

// could've used bitwise operations to calculate 2^N bc 1<<N = 2^N because bits are
// represented in the binary system

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int ans = 2;
    for (int i{1}; i < N; ++i) ans *= 2;
    ans -= 2*N;
    cout << ans << endl;
}
