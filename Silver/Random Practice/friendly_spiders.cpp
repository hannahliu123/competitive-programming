// CF - D. Friendly Spiders - R1800

// I tried a naive brute force approach because i thought the time complexity
// would just be O(N+M) which is nodes+edges. that's the normal time complexity
// for BFS because you only visit each node and edge once so i thought my time
// complexity would be O(N+N). In reality, for each node, my code is visiting all
// other N nodes, so it's actually O(N^2). 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, S, T;
    cin >> N;
    vector<int> a(N);
    for (auto& i : a) cin >> i;
    cin >> S >> T;
    S--; T--;

    vector<bool> visited(N, false);
    vector<int> prev(N, -1);
    queue<int> q{};
    vector<int> ans(N, -1);
    visited[S] = true;
    ans[S] = 1;
    q.push(S);
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        for (int i{0}; i < N; ++i) {
            if (visited[i] || gcd(a[n], a[i])==1) continue;
            visited[i] = true;
            prev[i] = n;
            ans[i] = ans[n] + 1;
            q.push(i);
        }
    }

    cout << ans[T] << endl;
    deque<int> ans2{T+1};
    int p = T;
    for (int i{0}; i < ans[T]; ++i) {
        p = prev[p];
        if (p != -1) ans2.push_back(p+1);
    }

    for (int i{0}; i < ans[T]; ++i) {
        cout << ans2.back() << ' ';
        ans2.pop_back();
    }
}
