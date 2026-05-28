// CSA - BFS-DFS

// okay so my idea got kinda complicated and hard to keep track of because i was
// trying to build a tree (so using as few edges as possible). the actual solution
// is stupidly simple. you just add an edge from 1 to every node in the order of
// the bfs traversal, then you add an edge between all consecutive nodes in the dfs
// traversal. omg so now it's guarenteed that you can always traverse the array in
// some way to achevie that order. tspo omgmgmgmg and the only time this isn't 
// possible is if the 2nd nodes are different ARGUAHEUHAU

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> B(N);
    vector<int> D(N);
    for (auto& i : B) {
        cin >> i;
    } for (auto& i : D) {
        cin >> i;
    }

    if (N==1) {
        cout << 0 << endl;
    } else if (D[1] != B[1]) {
        cout << -1 << endl;
    } else {
        cout << 2*N - 3 << '\n';
        for (int i=1; i < N; i++) cout << "1 " << B[i] << '\n';
        for (int i=2; i < N; i++) {
            cout << D[i-1] << ' ' << D[i] << '\n';
        }
    }
}
