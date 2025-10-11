// CSES - Maximum Subarray Sum

// Start: 9:33
// End: 9:46        13 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (auto& a : A) cin >> a;

    long long mxsum{A[0]}, sum{0};
    for (int i{0}; i < N; ++i) {
        if (sum+A[i] <= 0) sum = 0;
        sum += A[i];
        mxsum = max(mxsum, sum);
        if (sum < 0) sum = 0;
    }

    cout << mxsum << endl;
}

// WA - 14
