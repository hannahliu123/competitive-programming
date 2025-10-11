#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N{5};
    // adjacency list
    vector<int> adj[N+1];   // so we can skip 0

    // NOTE: brackets instead of parentheses

    adj[1].push_back(3);        // adding stuff
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[4].push_back(1);
    adj[5].push_back(4);
    adj[4].push_back(2);
    adj[4].push_back(3);

    for (int i{1}; i < N+1; ++i) {      // iterating through adj
        cout << i << ": ";
        for (int num : adj[i]) {
            cout << num << ' ';
        } cout << '\n';
    }
}
