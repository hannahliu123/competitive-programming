#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> X(N);
    for (auto& i : X) cin >> i;
    if (N==1) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i=0; i < N; i++) {
        int left=1e9, right=1e9;
        if (i>0) {
            left = (X[i] - X[i-1])/2;
            left += max((X[i-1] - X[0])/2, (X[N-1] - X[i])/2);
        } if (i<N-1) {
            right = (X[i+1] - X[i])/2;
            right += max((X[i] - X[0])/2, (X[N-1] - X[i+1])/2);
        }
        cout << min(left, right) << '\n';
    }
}