// broooo are we fr all i had to do was sort the input im actually gonna crash otu
// AKSDFHAKSDJFLDKJSFLKDSAJVFLKDJVLKADJVFSADFASDJFHAKJJ

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, K, T; cin >> N >> K >> T;
    vector<int> a(N);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());

    long long ans = 0;
    long long pre = 0;
    for (int i=0; i < N; i++) {
        long long start = a[i];
        if (pre >= T) break;
        long long end = start+K;
        if (pre < start) {
            if (start > T) start = T;
            ans += (start-pre + K-1)/K;
        }
        pre = end;
    }
    if (pre < T) {
        ans += (T-pre + K-1)/K;
    }

    cout << ans << '\n';
}