// the problem is essentially just given a string of N 0s, how do we turn on 3 (or fewer)
// bits to minimize the number of subsegments that are divisible by 3 when evaluated
// from binary to decimals

// clearly, we can see that the string will contain a LOT of zeroes because we can only
// have 3 ones at max. So, most of the string will be divisible by three because there
// will be a ton of chains of zeroes. BUT, notice when we place a 1 down, it must be at
// a power of 2. the powers of two have alternating remainders of 1 or 2. So, if you space
// an odd number of 0s in between two 1s, any chain containing 1 or both of those 1s will
// be non-iritating. However, now the issue arises of if and how we want to use that 3rd
// 1. If you place it an odd number of 0s away again, any chain containing all three will
// be irritating whereas a chain containing only the last two or just the last one will 
// be non-iritating (and the opposite for an even number of 0s away). well, wlil there be
// more chains containing only one or two or all three? well it completely depends on how
// we choose to arrange the numbers...

// Okay, so for 1 1, obviously just put it in the middle. For 2 1s, you wanna space them
// such that the lengths of the 3 chains of zeroes to the left, in between, and to the right
// are as small as possible. But now for 3 1s, 

// I should've immediately seen that because we can only place 3 1s, it is a good idea to
// try to evaluate each individual case seperately (1 1, 2 1s, 3 1s). Also, when the reasoning
// got complicated, I should've been looking for inversions that always hold or different
// ways to represent the modulos that can simplify the problem. Also I could've wrote a 
// program to brute force this more quickly rather than playing around with it by hand aimlessly

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