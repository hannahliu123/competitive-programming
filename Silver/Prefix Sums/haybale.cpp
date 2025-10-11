// Haybale Stacking - https://www.spoj.com/problems/HAYBALE/

// Start: 7:27
// End: 7:48        21 mins

// Yaaayyay i got it but I feel like I only knew the algorithm because I watched that
// video.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> stacks(N);
    while (K--) {
        int A, B;
        cin >> A >> B;
        stacks[--A]++;
        stacks[B]--;
    }

    for (int i{1}; i < N; ++i) {
        stacks[i] += stacks[i-1];
    }

    sort(stacks.begin(), stacks.end());
    cout << stacks[N/2] << endl;
}
