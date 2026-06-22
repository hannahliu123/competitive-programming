// ETF - Euler Totient Function

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;

    int MX = 1000000;
    vector<int> totient(MX+1);
    for (int i=0; i <= MX; i++) totient[i] = i;
    for (int p=2; p <= MX; p++) {
        if (totient[p] == p) {
            for (int i=p; i <= MX; i+=p) {
                totient[i] -= totient[i]/p;
            }
        }
    }

    while (t--) {
        int N; cin >> N;
        cout << totient[N] << '\n';
    }
}