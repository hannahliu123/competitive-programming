// USACO 2021 December Contest, Silver
// Problem 3. Convoluted Intervals

// Start: 7:35
// End: 8:34            59 minutes but i read the editorial after 40 mins

// We clearly can't have an O(N^2) solution, but we can abuse the fact that M is so small by
// having an O(M^2) component instead! It's so so so important for me to really realize and
// take advantage of smaller bounds and try to realize how you can compress an algorithm by
// using the overlap with the smaller bound. the answer was actually really straightforward
// once i saw the time complexity. I think i got tripped up by k=2M so i thought we didn't
// really need M for some reason? i honestly don't know how i missed this

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    
    vector<int> start(M+1, 0);
    vector<int> end(M+1, 0);
    for (int i=0; i < N; i++) {
        int a, b; cin >> a >> b;
        start[a]++; end[b]++;
    }

    vector<long long> ans(2*M+2, 0);
    for (int i=0; i <= M; i++) {
        long long cnti = start[i];
        long long cnti2 = end[i];
        if (cnti==0 && cnti2==0) continue;
        for (int j=0; j <= M; j++) {
            long long cntj = start[j];
            long long cntj2 = end[j];
            ans[i+j] += cnti*cntj;
            ans[i+j+1] -= cnti2*cntj2;
        }
    }

    cout << ans[0] << '\n';
    for (int i=1; i <= 2*M; i++) {
        ans[i] += ans[i-1];
        cout << ans[i] << '\n';
    }
}