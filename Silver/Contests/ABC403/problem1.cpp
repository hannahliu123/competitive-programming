// A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (auto& a : A) cin >> a;

    int ans{0};
    for (int i{0}; i < N; i+=2) ans += A[i];

    cout << ans << endl;
    return 0;
}
