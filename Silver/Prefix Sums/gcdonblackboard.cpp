// Atcoder - C - GCD on Blackboard

// This problem isn't a direct prefix sum problem. It's actually slight brute force, 
// where you test every possible value as the value taken out (replaced) and see if
// it's the max. However, in order to do that, you need two prefix arrays to calculate
// the GCD before and after that number.

// For example: A =  2                4           6            9
//  before: gcf of:  2                2 & 4       2 & 4 & 6    2 & 4 & 6 & 9
//  after:  gcf of:  2 & 4 & 6 & 9    4 & 6 & 9   6 & 9        9

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (auto& a : A) cin >> a;

    vector<int> before(N);
    before[0] = A[0];
    for (int i{1}; i < N; ++i) before[i] = gcd(A[i], before[i-1]);

    vector<int> after(N);
    after[N-1] = A[N-1];
    for (int i{N-2}; i >= 0; --i) after[i] = gcd(A[i], after[i+1]);

    int ans{1};
    ans = max(ans, max(before[N-2], after[1])); // takes care of first and last index
    for (int i{1}; i < N-1; ++i) {
        ans = max(ans, gcd(before[i-1], after[i+1]));
    }

    cout << ans << endl;
}
