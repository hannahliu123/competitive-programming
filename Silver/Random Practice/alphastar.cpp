#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int& a : A) cin >> a;

    vector<int> neg{};
    for (int i{0}; i < N; ++i) {
        if (A[i] < 0) neg.push_back(A[i]);
    }

    for (int n : neg) cout << n << ' ';

    for (int i{0}; i < N; ++i) {
        if (A[i] >= 0) cout << A[i] << ' ';
    }

    cout << endl;
}
