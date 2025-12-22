// You are given N≤20 numbers, each up to 1e9. Is there a subset with sum 
// equal to given goal S? (A subset means you can pick a group of any of the
// numbers and they don't need to be consecutive)

// The brute for solution (which is what we're gonna implement) is to just
// filter through every single possible subset and see if its sum is equal to
// S. There are 2^N possible subsets because you have two options for each of
// the N elements: add it to the sum or don't. You can use recursion, but a
// very neat implementation can be acheived by using a bitmask. The bitmask
// will contain a 1 when you want to select an elements and a 0 when you don't.
// We will generate a bitmask for every single possible combination. The bitmask 
// will just be the binary representation of each number from 0 to (2^N)-1. This
// is valid because zero is 000... which you need in cause S = 0. Then 2^N is
// equivalent to 1<<N which will be a 100... (with exactly N 0's following 1).
// That would result in a length of N+1 which is unnessecary. But (2^N)-1 would
// result in 111... with a total of N 1's. That means selecting every single
// value which is the maximum of what we need. This will take a total of O(2^N)
// time.
// As you iterate through each possible subset using a bitmask, you need to 
// calculate the sum of those value by iterating through the array in O(N) time.
// This results in a total time complexity of O(N * 2^N).

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 5, S = 1000;
    vector<int> a{1, 5, 2, 3, 9};

    bool pos = false;
    for (int mask{0}; mask < (1<<N); ++mask) {     // from 0 to (2^N)-1
        long long sum = 0;
        for (int i{0}; i < N; ++i) {
            if (mask & 1<<i) sum += a[i];
        }

        if (sum == S) {
            cout << "YES" << endl;
            pos = true;
            break;
        }
    } if (!pos) cout << "NO" << endl;
}
