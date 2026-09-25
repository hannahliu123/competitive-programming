// yayaya i really proud of my thought process for this one. it was really important
// that i notices how if the pirate decided to steal coins from pile i, then it's
// optimal to steal all coins from that pile. Then i had a series of other realizations
// that led me to the answer 

// ughh im really sad i didn't solve d tho because now some ppl are saying c was harder
// than d. i feel like i was just missing some little peice to D that i couldn't figure
// out because i was able to break down and unpack the problem a lot but i just couldn't
// find a solutionnnn

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, x; cin >> N >> x;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        vector<int> factors{};
        if (x%2==0) {
            factors.push_back(2);
            while (x%2==0) x/=2;
        }
        for (int i=3; i*i<=x; i+=2) {
            if (x%i==0) {
                factors.push_back(i);
                while (x%i==0) x/=i;
            }
        } if (x>1) factors.push_back(x);

        long long answer = 0;
        for (auto& f : factors) {
            long long ans = 0;
            for (int i=0; i < N; i++) {
                if (a[i]%f==0) ans += (long long)a[i];
            } answer = max(answer, ans);
        }

        cout << answer << '\n';
    }
}