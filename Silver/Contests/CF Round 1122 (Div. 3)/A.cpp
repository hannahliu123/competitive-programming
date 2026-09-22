#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        int weak = N-min(a[0], min(a[1],a[2]));
        cout << weak << '\n';
    }
}