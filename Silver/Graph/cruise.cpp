// USACO 2013 US Open, Silver
// Problem 3. Luxury River Cruise

// It's crucial here to realize there are small bounds given on purpose. N<=1000
// and M<=500, and N*M just so happens to be <=500000 (or 5*10^5). This is such a
// huge sign already that our solution will run in O(NM) time! Now, we also need
// to realize that if you start from port i and follow the directions, you will
// always end at port j because the directions don't change. So, if we follow the
// directions N times, we will at most end at N different ports, meaning there will
// always be a cycle within N repetitions of the sequence of directions. 

// But, i forgot to account for the fact that the graph isn't necessarily a direct
// loop. it could have a tail, THEN enter a loop. so, the best way to implement this
// is to construct a functional graph nxt such at nxt[i] results in the index bessie
// ends up at after completing M directions starting from i. We can just precompute
// N values within nxt[i] for each port

// okay the indexing for this problem was really tricky. i think if i was a bit more
// locked in and focused then i could've gotten this but uh i think the indexing still
// would've tripped me up a bit

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);

    int N, M, K; cin >> N >> M >> K;
    vector<int> l(N);
    vector<int> r(N);
    vector<char> s(M);
    for (int i=0; i < N; i++) {
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
    } for (int i=0; i < M; i++) cin >> s[i];

    vector<int> nxt(N); // functional graph 
    for (int i=0; i < N; i++) {
        int curr = i;
        for (auto& i : s) {
            if (i == 'L') curr = l[curr];
            else curr = r[curr];
        } nxt[i] = curr;
    }
    
    int curr = 0;
    if (K >= N) {
        // now we need to calculate cycle length & the cycle start port
        map<int,int> seen{};  // port idx: time
        int time = 1;
        while (seen[curr] == 0) {
            seen[curr] = time++;
            curr = nxt[curr];
        }

        // cycle_len = all visited groups of ports - time of repeated port
        int cycle_len = seen.size() - seen[curr] + 1;
        K = (K - seen[curr] + 1) % cycle_len;
    }

    for (int i=0; i < K; i++) curr = nxt[curr];

    cout << curr+1 << endl;
}
