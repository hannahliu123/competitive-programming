// USACO 2017 December Contest, Silver
// Problem 1. My Cow Ate My Homework

// Start: 10:24
// Pause: 10:48 - 9:00
// End: 9:18                couldn't figure out the last test case

// BRUHHH I JUST HAD TO SORT IT OMMGMGGMGMM

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> A(N);
    for (auto& a : A) cin >> a;

    long long sum{0};
    long long mn{A[N-1]};
    double divide{1};
    double average{0};
    double mx{0};
    vector<int> K{};
    for (int i{N-2}; i >= 1; --i) {     // includes i
        if (A[i] < mn) {
            sum += mn;
            mn = A[i];
        } else sum += A[i];
        average = sum/divide++;
        if (average > mx) {
            mx = average;
            K = {i};
        } else if (average == mx) {
            K.push_back(i);
        }
    }

    sort(K.begin(), K.end());
    for (int k : K) cout << k << '\n';
}

// X - 3-10
// X - 10
