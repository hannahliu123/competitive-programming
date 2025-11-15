// CF - C. Save the Nature - R1600

// Start: 11:22
// End: 12:03       // 41 minutes

// Bro tell me why i submitted my solution at 12:03 and it only finished grading 
// at 12:24. OVER TWENTY MINUTES BRO make that make sense :((((. Anyways I used
// binary serach and i feel like this will def be in the usaco contest. def 1
// binary search problem and 1 graph problem and idk abt the other one.

// yeah okay the solution is basically identical les gooooo

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int N;
        cin >> N;
        vector<long long> p(N);
        for (auto& i : p) cin >> i;
        sort(p.rbegin(), p.rend());   // g -> l
        int x, A, y, B;
        long long k;
        cin >> x >> A >> y >> B >> k;   // %, nth
        if (y > x) {    // x >= y
            swap(x, y);
            swap(A, B);
        }

        // binary search on the ans (min number of tickets sold)
        int hi = N, lo = 1;
        int ans = -1;
        while (hi >= lo) {
            int mid = lo + (hi - lo) / 2;   // try selling mid # of tickets
            int both = 0, a = 0, b = 0;
            for (int i{1}; i <= mid; ++i) {
                if (i % A == 0 && i % B == 0) both++;
                else if (i % A == 0) a++;
                else if (i % B == 0) b++;
            }

            int index = 0;
            long long revenue = 0;
            for (int j = 0; j < both; ++j) {
                revenue += p[index++] * (x+y) / 100;
            } for (int j = 0; j < a; ++j) {
                revenue += p[index++] * x / 100;
            } for (int j = 0; j < b; ++j) {
                revenue += p[index++] * y / 100;
            }

            if (revenue >= k) {
                hi = mid;
                ans = hi;
                if (hi == lo) break;
            } else {    // rev < k 
                if (hi == lo) break;
                lo = mid+1;
            }
        }

        cout << ans << endl;
    }
}
