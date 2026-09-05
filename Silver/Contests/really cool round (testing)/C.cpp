#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        int f1=N, l1=-1;   // first and last occurances of 1
        int fn1=N, ln1=-1;   // first and last occurances of -1
        for (int i=0; i < N; i++) {
            cin >> a[i];
            if (a[i]==1) {
                if (f1==N) f1=i;
                l1=i;
            }
            else if (a[i]==-1) {
                if (fn1==N) fn1=i;
                ln1=i;
            }
        }

        for (int i=0; i < N; i++) {
            if (a[i]==-1) {
                if ((i==fn1 && i<f1) || (i==ln1 && i>l1)) a[i] = 1;
                else a[i] = 0;
            }
        }

        for (auto& i : a) cout << i << ' ';
        cout << '\n';
    }
}