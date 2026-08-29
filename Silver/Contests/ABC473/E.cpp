#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> a(N);
    for (auto& i : a) cin >> i;

    int i=0;
    int ans = 0;
    while (i < N) {
        map<int,int> m{};
        long long sum = 0;
        for (int j=i; j < N; j++) {
            sum += a[j];
            int rem = sum%K;
            if (m[rem]>0 || rem==0) {
                ans++; i=j+1; break;
            } if (j == N-1) i=N;
            m[rem]++;
        }
    }

    cout << ans << endl;
}