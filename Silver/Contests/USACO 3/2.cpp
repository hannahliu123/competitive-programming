// USACO 2026 Third Contest, Silver
// Problem 2. Milk Buckets

// i think i know where my logic was flawed but idk if there was something else
// missing in my code. its so annoyign that you cant try submitting solutions after
// the contest ends but ig it makes sense to prevent cheating etc

// omg i think the other reason my code didnt work is because i forget freaking
// parentheses in my final calculation. i thought it wouldn't matter cos its just
// multiplication and division, but it does because i wanted the result of trucation
// after the divison so i wanted division to happen first!

// oh frick now im realizing that mult will overflow by WAYYY too much. because each
// capacity can be 10^9 and we have potentially 2*10^5 values, multiplying all of them
// together would result in (10^9)^(2*10^5). Holy moly yeah no that would not work at 
// all. that explains the ! error ig

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> cap(N); // capacity
    for (auto& i : cap) cin >> i;
    
    vector<long long> need(N, 1);    // number of pours needed from prev
    long long mult = 1;
    for (int i{1}; i < N; ++i) {
        long long x = (long long)cap[i]/cap[i-1];
        if (cap[i]%cap[i-1]>0) x++; // round up
        need[i] = x;
        mult *= x;
    }

    int Q; cin >> Q;
    while (Q--) {
        int i, v;    // cap[i] = v (persists through all queries)
        long long t;
        cin >> i >> v >> t; i--;

        cap[i] = v;
        if (i>0) {
            // update how many pours from the previous bucket needed to fill i
            mult /= need[i];
            long long x = ((long long)cap[i]/cap[i-1]);
            if (cap[i]%cap[i-1]>0) x++; // round up
            need[i] = x;
            mult *= need[i];
        } if (i<=N-2) {
            // update how many pours from i needed to fill the next bucket
            mult /= need[i+1];
            long long x = ((long long)cap[i+1]/cap[i]);
            if (cap[i+1]%cap[i]>0) x++; // round up
            need[i+1] = x;
            mult *= need[i+1];
        }

        t -= (long long)(N-1);
        long long y = t/(cap[0]+1);

        cout << cap[N-1]*(y/mult) << '\n';
    }
}
