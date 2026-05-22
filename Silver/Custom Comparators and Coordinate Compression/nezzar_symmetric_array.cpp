// CF - C. Nezzar and Symmetric Array - R1700

// Start: 8:39
// End: 9:44        1 hr 5 mins

// Okay so im lowkey surprised i got this solution. my math was super messy lol and i
// wasn't entirely confident it was gonna work. then i got a WA so i had to look at 
// the failed test case (i know i def wouldn't have figured it out if i hadn't looked
// at the test case). erm so i just did some math and rearranging equations to get this
// solution and the part i changed after the WA was that a had to not only not be 0, but
// it also couldn't be negative (lol i should've known that answers wtv). um so to get
// to the math i just had to make the greedy realization that if a_i < a_j, the sum
// contribution to d_i would  be 2*a_j. On the other hand, if a_i >= a_j, the sum contr.
// would be 2*a_i

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<long long> d(2*N);
        for (auto& i : d) cin >> i;
        sort(d.begin(), d.end());

        long long sum = 0;
        int idx = N;
        bool pos = true;
        set<long long> seen{};
        for (int i=2*N-1; i >= 0; i-=2) {
            if (d[i] != d[i-1]) {
                pos = false;
                break;
            }

            long long rem = (d[i] - sum) % (2*idx);
            long long a = (d[i] - sum) / (2*idx--);
            if (rem > 0 || a<=0 || seen.count(a)) {
                pos = false;
                break;
            }
            
            seen.insert(a);
            sum += 2*a;
        }

        cout << (pos? "YES\n" : "NO\n");
    }
}
