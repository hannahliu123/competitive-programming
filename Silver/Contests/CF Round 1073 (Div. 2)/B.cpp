// B

// i lowkey really struggled on this one and couldn't figure out the answer... 
// i kinda just guessed a greedy solution and crossed my fingers and hoped and
// prayed it would work. and it did! but i really didn't like how i approached
// solving this :(

// ok so this problem just involves breaking the problem into smaller subtasks
// (ish) and making careful evaluations for each one. specifically, it involves
// looking at how the number of zeros affects the final result. notice that if
// you keep all the zeroes together, the mex without the zeros will be zero (duh
// bc there are no zeroes). then on the side with the zeroes, the mex will start
// as one, and then if it meets a one, it will advance to two, and so on. The
// only place where the mex of the left & right sides will be equal is where a 
// zero is present on both or neither side. if there are no zeros, obviously the
// answer is no because the mex will always be zero. if there is one zero, the 
// answer will always be yes because on one side there's a zero (mex>0) whilst on
// the other size there isn't a zero (mex=0). but if there are multiple zeroes, 
// you can split the array such that mex on both sides is >0 (zero present on both
// sides). it's always desireable to have the zeroes on the outermost edges because
// it guarentees the left mex starts >0 whilst the right mex remains at 0 all the
// way until it reaches a zero. if a 1 was somewhere present, then the right mex
// would jump to 2 when it reaches its first zero. on the other hand, if a 1 is not
// present, it would only jump to 1. this is an issue, because the mex for the right
// would still be 1 during the zeros chain. so, this means that if there are 
// multiple zeroes, the answer is yes only if a 1 is present within the array.

// this is a very confusing problem imo but i think intuitively you would want to 
// sort the array (gut feeling idk). i feel like this is very different from a usaco
// or atcoder problem as it is so purely based on greedy thinking. oh okay so this
// type of problem is actually called constructive algorithms. it's essentially just
// trying to find patterns and definite rules to form an answer. i don't really like
// this type of problem but wtv

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        bool pos = true;
        vector<int> a(N);
        for (int i{0}; i < N; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        int mex = 0;
        vector<bool> seen(N+1, false);
        vector<int> fw(N);  // mex forward
        for (int i{0}; i < N; ++i) {
            seen[a[i]] = true;
            while (seen[mex]) mex++;
            fw[i] = mex;
        }
        
        mex = 0;
        seen.clear();
        seen.resize(N+1, false);
        vector<int> bw(N);  // mex backward
        for (int i{N-1}; i >= 0; --i) {
            seen[a[i]] = true;
            while (seen[mex]) mex++;
            bw[i] = mex;
        }

        for (int i{0}; i < N-1; ++i) {
            if (fw[i] == bw[i+1]) {
                pos = false;
                break;
            }
        }

        if (pos) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
