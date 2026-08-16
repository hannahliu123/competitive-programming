// USACO 2026 Third Contest, Silver
// Problem 2. Milk Buckets

// I spent 1 hour on this and i almost think i got a solution but i have a problem where
// idk how to avoid overflow beause i need to maintain a mult variable that is just the
// of all scale factors from one bucket capacity to the next, which can easily exceed
// the max value of a long long. clearly no data type can house that large of a value, so
// now idrk what to do

// oh wow okay so to keep track of the multiples, it's key here to notice that each time
// we have a multiplier greater than 1 (so impactful cos x1 does nothing), it will at the
// very least double the old value. say if we start with the minimum possible capacity (1),
// the start value would be zero. we know the maximum period is 10^18 because that's the
// max time. if the period exceeds 10^18 then the answer is zero. Okay, knowing this, if
// each multiple is the absolute minimum (x2), we can have 59 maximum multiples. if the
// number of multiples reaches 60, we'll have a period of 2^60 > 10^18. Thus, we just need
// to keep track of a big list of all the multiples and if the size is less than 60, we can
// try multiplying them all together. If during that process though the value exceeds 10^18,
// the answer is invalid and we output 0.

// final takeaway is there are ways to combat overflow error ig. like especially when the
// overflow is THAT large. also yk how for time complexity you have to consider the worst
// case senario? well for this problem you in a way had to consider the best case senario
// (like smallest possible values of scale factor changes in capacities) to get to that
// final realization

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> a(N);
    for (auto& i : a) cin >> i;

    multiset<int> multipliers{};
    for (int i=1; i < N; i++) {
        if (a[i] <= a[i-1]) continue;
        multipliers.insert((a[i] + a[i-1] - 1)/a[i-1]); // round up
    }

    int Q; cin >> Q;
    while (Q--) {
        int i, v; long long t;
        cin >> i >> v >> t; i--;

        if (i>0 && a[i] > a[i-1]) {     // we only wanna erase ONE value
            auto it = multipliers.find((a[i]+a[i-1]-1)/a[i-1]);
            multipliers.erase(it);
        }
        if (i<N-1 && a[i+1] > a[i]) {
            auto it = multipliers.find((a[i+1]+a[i]-1)/a[i]);
            multipliers.erase(it);
        }
        a[i] = v;
        if (i>0 && a[i] > a[i-1]) multipliers.insert((a[i]+a[i-1]-1)/a[i-1]);
        if (i<N-1 && a[i+1] > a[i]) multipliers.insert((a[i+1]+a[i]-1)/a[i]);

        if (t < (long long)N || multipliers.size() > 59) {
            cout << 0 << '\n'; continue;
        }

        long long mult = 1;
        for (auto& m : multipliers) {
            if (mult > (long long)1e18 / m) {
                mult = -1; break;
            }
            mult *= (long long)m;
        }

        if (mult == -1) {
            cout << 0 << '\n'; continue;
        }

        long long start = start = a[0]+1;
        long long P = start*mult;   // period
        long long pool = (t-N+1)/P;     // number of dumps into the pool
        cout << pool*(long long)a[N-1] << '\n';
    }
}