// CSES Problem Set - Maximum Manhattan Distances

// I was stuck on the seemingly simple problem for so long, trying to figure out
// the right greedy observation or trying to apply some algorithm. In reality i 
// would say this is just a math problem cos all u needed to do was rearrange the
// formula. Manhattan distance between 2 pts is |x1-x2| + |y1-y2|. this is tricky
// because the x and y values are each dependent on eachother so theres no good
// way to just know the best point to pair each x1 y1 with in O(log N) or O(1) time.
// BUT if we were able to rearrange it such that the x1 and y1 were together and the
// x2 and y2 were together, it would be much easier. We can rewrite this expression
// (currently using absolute values) into the max of 4 statements depending on
// whether x1 vs x2 or y1 vs y2 is larger (and the sign: +/-)
// (x1-x2) + (y1-y2) = x1+y1-x2-y2 =    (x1+y1) - (x2+y2)
// (x2-x1) + (y1-y2) = -x1+y1+x2-y2 =   -(x1-y1) + (x2-y2) = (x2-y2) - (x1-y1)
// (x1-x2) + (y2-y1) = x1-y1-x2+y2 =    (x1-y1) - (x2-y2)
// (x2-x1) + (y2-y1) = -x1-y1+x2+y2 =   -(x1+y1) + (x2+y2) = (x2+y2) - (x1+y1)
// Now we can clearly see that among all possible points, the maximum distance will
// be between 2 points x1,y1 and x2,y2 (could be swapped depending on what's more
// desireable) such that (x1+y1)-(x2+y2) or (x1-y1)-(x2-y2) is maximized. so clearly
// we want that first term to be as large as possible and the second term to be as
// small as possible. The final dist will just be max(mxsum-mnsum, mxdiff-mndiff)
// were each of the 4 variables in those expressions is unique to each individual
// point we process and nothing else. Knowing this, the implementation is very
// simple b/c we only need to track four variables

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    long long mxsum=0, mnsum=0, mxdiff=0, mndiff=0;
    long long mx = 0;
    for (int i=0; i < N; i++) {
        long long x, y; cin >> x >> y;

        if (i==0) {
            mxsum=x+y, mnsum=x+y, mxdiff=x-y, mndiff=x-y;
        } else {
            mxsum = max(mxsum, x+y);
            mnsum = min(mnsum, x+y);
            mxdiff = max(mxdiff, x-y);
            mndiff = min(mndiff, x-y);
        } mx = max(mxsum-mnsum, mxdiff-mndiff);

        cout << mx << '\n';
    }
}