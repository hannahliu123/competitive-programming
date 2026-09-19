// B2. Carrot Chopdown (Hard Version) - R1600

// the key to this problem is to break it down under more simplified constraints. for
// example, i should've tried what happens if x is fixed or k is fixed. i also did notice
// that the max number of operations you can perform is log_2(M), which is about 18. Thus,
// after 18 operations (k>18), the answer will just be the sum of all a_i. BUT now before
// then, say you have a fixed target value x. The final operation should obviously be x.
// the second to last should be 2x. Third to last should be 4x. Then 8x and so on. This
// will maximize your final amount of items at x. Now, when k is fixed (from 1->M), we
// know there will be 2^k peices for each a_i after k operations. For some x, in the most
// ideal situation, a_i = 2^k * x, so each of the 2^k peices will end up with length x.
// However, if a_i < 2^k * x, then it will produce a_i/x (floor) peices of length x because
// all possible x's will be made. If a_i > 2^k * x, it will produce 2^k-1 peices of length
// x because the very last peice will just be too high but all others would be of length x.
// So, for each a_i, its contribution is a_i/x. But for all a_i > 2^k * x, we decrement the
// contr by 1.

// We want to maximize the contributions across the entire array a for some value x given a
// fixed k (well we only need to process k from 1 to log_2(M)). For each fixed k, it's key
// to notice that we should only try x values such that a_max >= 2^k * x or else you'd have
// extra wasted operations. So, this must hold: x <= a_max/2^k, or x <= M/2^k. This means, for
// our 18 k values, we just process x from 1 to M/2^k, which results in M*(1/2^k)

// wait bro idek anymore i think u can try x from 1 to M and you'll still fit in the time complexity

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        vector<int> a(N);
        for (auto& i : a) cin >> i;


    }
}
