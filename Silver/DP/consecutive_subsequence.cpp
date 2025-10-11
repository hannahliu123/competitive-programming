// CF - Consecutive Subsequence - R1700

#include <bits/stdc++.h>
using namespace std;

// Took a second for me to understand (cos if indexing vs values)

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (auto& A : a) cin >> A;

    vector<int> lcs(N, 1);  // tracks longest consecutive subsequence
    vector<int> prev_index(N, -1);  // tracks previous index used for lcs
    map<int, int> seen{};   // value, index

    for (int i{0}; i < N; ++i) {
        if (seen.count(a[i]-1)) {     // 0-indexed
            lcs[i] = lcs[seen[a[i]-1]]+1;
            prev_index[i] = seen[a[i]-1];  // 0-indexed (for now)
        }
        seen[a[i]] = i;
    }

    int k{0};
    int prev{-1};
    for (int i{0}; i < N; ++i) {
        if (lcs[i] > k) {
            k = lcs[i];
            prev = i;
        }
    }

    cout << k << '\n';

    vector<int> sequence{prev};
    while (prev != -1) {
        sequence.push_back(prev_index[prev]);
        prev = prev_index[prev];
    }

    int i = sequence.size()-1;
    for (i; i >= 0; --i) {
        if (sequence[i] != -1) cout << sequence[i]+1 << ' ';
    }

    cout << endl;
}
