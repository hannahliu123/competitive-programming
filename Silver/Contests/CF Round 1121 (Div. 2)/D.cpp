// the problem is essentiall just given a string of N 0s, how do we turn on 3 (or fewer)
// bits to minimize the number of subsegments that are divisible by 3 when evaluated
// from binary to decimals

// clearly, we can see that the string will contain a LOT of zeroes because we can only
// have 3 ones at max. So, most of the string will be divisible by three because there
// will be a ton of chains of zeroes. BUT, notice when we place a 1 down, it must be at
// a power of 2. the powers of two have alternating remainders of 1 or 2.

// ugh this is wrong i think this is literlaly just greeedy dsjfalsdkfjlaksdjf ill come back later

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;

        if (N==1) {
            cout << "1\n"; continue;
        } if (N==2) {
            cout << "11\n"; continue;
        } 

        int idx = N/2 - 1;
        for (int i=0; i < N; i++) {
            if (i==idx || i==idx+2) cout << 1;
            else cout << 0;
        } cout << '\n';
    }
}