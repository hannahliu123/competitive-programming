// This was easier than D imo and i sovled it first. it was essentially just a greedy
// and prefix sums and two pointers mix kind of thing but the intuition was pretty 
// straightforward. you can quickly realize you can just greedily take all the multiples
// of 8 as you encounter them, and that can be done using prefix sums and tracking what
// remainders youve already encountered. the time contraints are loose too so u can just
// use a map (actually a set would've worked too but wtv)

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