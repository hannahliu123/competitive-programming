// Atcoder - E - Xor Sigma Problem - https://atcoder.jp/contests/abc365/tasks/abc365_e

// the original problem is asking for every possible subarray, find the sum of the XOR
// of all values in each subarray. However, we can frame the problem as for each bit
// position, we how many subarrays exist such that this bit is turned on. If S_i
// combinations exist such that the ith bit is turned on, we know that 1<<i (or 2^i)
// is contributed to the total sum S_i times. This works because XOR is independent
// based on bit positions (no carry over). 

// So now, in order to calculate how many total subarrays exist with the ith bit turned
// on, we should know that a subarray will have a value of 1 at the position i after
// XORing all elements in the subarray if and only if it all elements of the subarray
// contain an odd number of 1s (duh b/c it's like toggling). To count these "odd-count"
// subarrays efficiently in O(N) time, we can track the running prefix XOR parity (so
// wether or not the prefix xor value of the elements at index i are odd/even). With
// this, for two indexes l and r, pref[r+1] XOR pref[l] tells us if the subarray from
// l to r results in XOR of 1 or 0. But to avoid looping through all values of l and r,
// we keep a running count how many indexes in the prefix array are odd and how many
// are even. we want the total number of combinations of l and r such that they have
// opposite prefix values (one is odd and one is even). So as we loop through our array
// of numbers, if the current number we visit is our ending index (r), we know that we
// can chose all l indexes that have the opposite parity as the current index to create
// a valid subarray with an XOR contribution of 1. So, if r is current odd, we know we
// can create x subarrays (l, r) where x equals the number of even indexes we've seen.
// Then, once we finish iterating through the whole array, we multiply the total subarrays
// (S) by the actual value contribution (which is 2^i, or 1<<i) then add that to our
// answer. Doing this for even bit position i allows us to acheive the right answer 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (auto& i : v) cin >> i;

    long long ans = 0;
    // for each bit position (we only need 30 because v[i] <= 1e8)
    for (int i=0; i < 30; i++) {
        int odd = 0;
        int even = 1;   // pref[0] = 0 so even starts at 1
        bool curr = 0;
        int cnt1s = 0;
        long long subarrays = 0;    // LL cos we can have N(N+1)/2 subarrays
        for (int r=1; r <= N; r++) {            
            if (v[r-1] & (1<<i)) { // if bit i is turned on in v[r-1]
                curr = !curr;
                cnt1s++;
            } if (curr) {   // currently odd
                subarrays += even;
                odd++;
            } else {    // currently even
                subarrays += odd;
                even++;
            }
        }

        subarrays -= cnt1s;   // you can't have subarrays with only 1 elem

        ans += (1LL << i) * subarrays;
    }

    cout << ans << endl;
}
