// CF - C. To Become Max - R16x00

// Start: 2:00
// End: 2:32        32 mins

// THANK YOU FINALLY AN EASY PROBLEM

#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> a;
vector<int> pot;    // max potential

bool check(int mid) {
    for (int i=0; i < N; i++) { // try to make mid at a[i]
        if (pot[i] < mid) continue; // impossible

        long long ops = 0;
        int mid2 = mid;
        for (int j=i; j < N; j++) {
            if (a[j]>=mid2) {
                if (ops <= (long long)K) return true;
                break;
            } ops += (long long)mid2-a[j];
            mid2--;
        }
    }
    
    return false;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> N >> K;
        a.resize(N);
        for (auto& i : a) cin >> i;

        pot.resize(N);
        pot[N-1] = a[N-1];
        int lo = a[N-1], hi = a[N-1];
        for (int i=N-2; i >= 0; i--) {
            pot[i] = max(pot[i+1]+1, a[i]);
            lo = max(lo, a[i]);
            hi = max(hi, pot[i]);
        }

        // binary search on the ans (true if we can make mid using K or less operations)
        while (lo < hi) {
            int mid = (lo+hi+1)/2;

            if (check(mid)) lo = mid;
            else hi = mid-1;
        }

        cout << lo << '\n';
    }
}