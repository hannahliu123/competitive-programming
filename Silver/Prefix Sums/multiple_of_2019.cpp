// AtCoder - D - Multiple of 2019

#include <bits/stdc++.h>
using namespace std;

// First, consider a O(N^2) solution using a suffix array and modulo properties. Let's
// call M = 2019. If we want to test every index i and j to see if the value between those
// indexes are divisible by M, we can use a SUFFIX array which contains the number from the
// current index to the end of the string. With a suffix array, if you subtract two values
// from eachother, you end up with the correct value between (and some zeroes at the end).
// We don't care about those zeroes at the end because if any number n was divisible by
// 2019, n0 or n00 or n00 etc would also be divisible by 2019 because you're just multiplying
// by 10 and 2019 doesn't end with a 0. But, if we loop through all possible pairs of i
// and j then see if the difference in suffix values is divisible, we would run out of
// space because N <= 2*10^5 whereas a long long can only store up to 18ish digits! As a
// result, we need to realize that a subtrings (which is suff_left - suff_right) is divisible
// by M if (suff_left - suff_right) % M = 0. If you rearrange that (a key property of modulos), 
// you get (suff_left%M) - (suff_right%M) = 0, or in otherwords, the remainder of each suffix
// is equal. Now, that we have a O(N^2) solution, we need to optimize it to be more efficient.

// To do this, for each index i, we can try to track the number of values that would result
// in an equal remainder. To do this, we just need a frequency array from 0 to 2018 that
// counts how many suffixes have a remainder of that value. However, this would result in
// lots of double counting, so instead we can use combinatorics. So for each remainder value,
// we want to know how many combinations of indexes/how many different substrings we can 
// acheive. In other words, we want to know how many combinations of size 2 we can make.
// nCr(n,2) = n! / (2!)(n-2)! = n(n-1)(n-2)! / (2*1)(n-2)! = n(n-1)/2

int main() {
    string s; cin >> s;
    
    int N = s.length();
    vector<int> remFreq(2019, 0);   // frequency count for each remainder value
    remFreq[0]=1;   // for the case i=N (nothing selected)
    long long pow = 1;    // keeps track of zeroes after each num
    int rem = 0;
    for (int i=N-1; i >= 0; i--) {
        int num = s[i] - '0';
        rem = (rem + (num*pow)) % 2019;
        remFreq[rem]++;
        pow = (pow*10) % 2019;  // prevent overflow
    }

    long long ans = 0;
    for (int i=0; i < 2019; i++) {
        ans += (long long)(remFreq[i]) * (remFreq[i]-1) / 2;
    }

    cout << ans << '\n';
}
