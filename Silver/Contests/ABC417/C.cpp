// UPSOLVE AFTER CONTEST

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (auto& i : a) cin >> i;

    map<int, int> occurances;     // how many times i + a[i] has occurred
    long long ans{0};
    for (int i{0}; i < N; ++i) {
        int curr = i - a[i];
        ans += occurances[curr];
        occurances[i + a[i]]++;
    }

    cout << ans << endl;
}
