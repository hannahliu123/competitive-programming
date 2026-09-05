#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        int zeroes = 0;
        for (int i=0; i < N; i++) {
            cin >> a[i];
            if (a[i]==0) zeroes++;
        }

        if (zeroes==1) cout << "NO\n";
        else if (zeroes==0) {
            cout << "YES\n";
            for (int i=0; i < N; i++) cout << "C";
            cout << '\n';
        } else {
            cout << "YES\n";
            bool givenA = false;
            for (int i=0; i < N; i++) {
                if (a[i]==0) {
                    if (!givenA) {
                        cout << "A";
                        givenA = true;
                    } else cout << "B";
                } else cout << "C";
            } cout << '\n';
        }
    }
}