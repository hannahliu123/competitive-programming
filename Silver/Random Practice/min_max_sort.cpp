// CF - C. Min Max Sort - R1500

// Start: 8:57
// End: 10:07       1hr 10mins

// k so i had the idea early on but i tried to over-optimize it. My solution runs in O(N)
// time regardless so that was pointless. i also am quick to assume greedy ideas but im glad
// i was able to debug this

// alright so the idea for my solution and the editorial is the same, except i think i
// jumped into the code way before i should've. i didnt have a solid idea yet but i alr
// started with the implementation. instead i should take a few extra minutes and identify
// a more straightforward impelmentation. i should also wait until im actually confident in
// the code because this could've gone a LOT worse. there are so many easier ways i could've
// implemented this code :')

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        
        vector<int> p(N+1, 0);  // 0=empty, pos=chain starting from i, neg=joined chain from i
        for (int i{0}; i < N; ++i) {
            int x; cin >> x;
            if (p[x-1] == 0) p[x] = 1;
            else if (p[x-1] > 0) {
                p[x] = -(x-1);
                p[x-1]++;
            } else {
                p[x] = p[x-1];
                p[-p[x-1]]++;
            } 
        }

        int mn = 0;
        int exc = (N%2==0? -1 : (N/2)+1);   // can't be this
        for (int i{1}; i <= N; ++i) {   // p[i] = length, i=start index
            if (p[i] <= 0) continue;
            int bef = 0, aft = 0;   // cnt before and after the middle
            for (int j{i}; j < i+p[i]; ++j) {
                if (j==exc) continue;
                if (j <= N/2) bef++;
                else aft++;
            } mn = max(mn, min(bef, aft));
        }

        cout << N/2 - mn << endl;
    }
}
