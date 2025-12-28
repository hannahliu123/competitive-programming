// CF - F. Cluster Computing System - R1600

// The greedy observation is that you always want one endpoint to be either the
// very first server or the last server (this is most optimal because as you add
// more numbers to gcd, the gcd will only ever get smaller). It's always optimal
// to have the gcd from the first to the last server as well and for all other
// servers (2 to N-1) you want to connect it to either the first or last server.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (auto& i : p) cin >> i;

    // calculate prefix (for connecting i with the first server)
    vector<int> pref(N);
    pref[0] = p[0];
    for (int i{1}; i < N; ++i) {
        pref[i] = gcd(p[i], pref[i-1]);
    }

    // calculate suffix (for connecting i with the last server)
    vector<int> suff(N);
    suff[N-1] = p[N-1];
    for (int i{N-2}; i >= 0; --i) {
        suff[i] = gcd(p[i], suff[i+1]);
    }

    long long ans = pref[N-1];  // connecting first & last servers
    for (int i{1}; i < N-1; ++i) {  // for all other servers
        ans += min(pref[i], suff[i]);
    }

    cout << ans << endl;
}
