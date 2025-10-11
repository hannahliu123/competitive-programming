// CF - Greg and Array - R1400

// Start: 11:16
// End: 11:40 

// Stopped because idk how to fix the memory limit problem :(

// Alright so I read the solution, then died cos i didn't rly understand what was 
// happening, then I ate lunch, then I procrastinated, and now i came back to it. 
// All i needed to do was draw out the test cases to really understand the indexing

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> A(N);
    for (auto& a : A) cin >> a;

    vector<vector<long long>> updates(M, vector<long long>(3));
    for (int i{0}; i < M; ++i) {
        cin >> updates[i][0] >> updates[i][1] >> updates[i][2];
    }

    vector<long long> op(M+1);  // will track number of times each operation is applied
    while (K--) {
        int X, Y;
        cin >> X >> Y;
        op[X-1]++;
        op[Y]--;
    }

    for (int i{1}; i <= M; ++i) {
        op[i] += op[i-1];
    }
    
    vector<long long> add(N+1);
    for (int i{0}; i < M; ++i) {
        add[updates[i][0]-1] += updates[i][2]*op[i];
        add[updates[i][1]] -= updates[i][2]*op[i];
    }

    for (int i{1}; i <= N; ++i) {
        add[i] += add[i-1];
    }

    for (int i{0}; i < N; ++i) {
        cout << A[i]+add[i] << ' ';
    } cout << endl;
}

// Memory Limit Exceeded
// WA - 11
// WA - 26
