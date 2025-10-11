// CF - D. Vertical Paths - R1300

// Start: 9:25
// End: 10:04       39 mins

// Stop im actually so proud of this even though it was so simple. you just had to count
// the leaves omg! Hey im still proud cos i figured this one out really clean-ly and

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<vector<int>> sections;
vector<int> section;
int M;      // # of paths (leaves)

void dfs(int node, int prev) {
    if (tree[node].size() == 0) {   // end of path
        M += 1;
        sections.push_back(section);
        section = {};
    }
    
    for (auto i : tree[node]) {
        if (i != prev) {
            section.push_back(i);
            dfs(i, node);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        M = 0;
        tree.clear();
        tree.resize(N);
        sections.clear();
        int root = -1;
        for (int i{0}; i < N; ++i) {
            int p;
            cin >> p;
            p--;

            if (p == i) root = i;
            else tree[p].push_back(i);
        }

        section = {root};
        dfs(root, -1);

        // Print answer
        cout << M << '\n';
        for (auto& i : sections) {
            cout << i.size() << '\n';
            for (int n : i) {
                cout << n+1 << ' ';
            } cout << '\n';
        }
        
        cout << endl;
    }
}
