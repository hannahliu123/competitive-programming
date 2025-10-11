// USACO 2019 January Contest, Silver
// Problem 1. Grass Planting

// Start: 1:40
// End: i checked the solution

// I don't know enough about trees or coloring or graphs in general to have thought
// of this solution, but if I got this problem during a contest, I might have been 
// able to figure it out if I just kept drawing smaller test cases and writing like
// the charts I was making. I could've noticed that even with really big graphs, the
// answer would still be very small unless there were all connected at one point
// (degree). I was actually kinda close to seeing that. I need to stop giving up so
// soon. Next time I'm gonna set a timer. Maybe 30 minutes just for me and and paper.

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> adj[N];
    for (int i{0}; i < N-1; ++i) {
        int num1, num2;
        cin >> num1 >> num2;
        adj[num1-1].push_back(num2-1);
        adj[num2-1].push_back(num1-1);
    }

    int mx{0};
    for (int i{0}; i < N; ++i) {
        mx = max(mx, static_cast<int>(adj[i].size()));
    }

    cout << mx+1 << endl;
}
