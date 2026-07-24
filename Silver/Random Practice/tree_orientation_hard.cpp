// CF - D2. Tree Orientation (Hard Version) - R2200

// so condensing this down to O(N^2) means that for each node, we need to be able to 
// figure out what child it will have a direct edge to without processing indirect
// children. Right now the O(N^3) solution wastes efficiency by processing the children
// of all children, but it is optimal for us to only process the children of the child
// with the most children. Because that child is 100% a direct edge to node i, we only
// process each of those direct nodes once in total so that's just adding N to the time
// complexity which doesn't do anything. So, we need a way to be able to loop through all
// the children of i (in adj[i]) but know exactly whether or not we want to process that
// child. We can't have a O(N^2 log N) time, so that means if we wanted to sort anything,
// we need to do that seperately in O(N log N), meaning we can only sort one vector of
// size N. 

// So, what we can do is pre-sort every node from most number of eventual children to 
// least. then for each i, we can actually loop through every node 0->N-1 (not just adj[i])
// and see if that node is a part of adj[i]. in this way, we process the node with the
// largest number of children first. we need adj[i] to be an unordered_set tho. then for
// each of the children of that child node, we remove those children from adj[i] so we
// don't reprocess them. we can't directly change adj[i] tho because we might need it later
// when processing other nodes in case there's a direct edge from some node to i. so, we
// can just make a copy within the iteration

// HOLY FREAKING FRACK BRO ARE YOU FR RIGHT NOW WHAT THE HECK

#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> adj;
vector<pair<int,int>> sorted;   // children, index
vector<pair<int,int>> all_edges;
bool pos;
vector<vector<int>> adj2;
vector<bool> visited;
int total_visited;

void create_edges(int node) {
    string s = adj[node];
    for (auto p : sorted) {
        if (s[p.second]=='1') { // p.second is the child with most children
            all_edges.push_back({node, p.second});
            if (all_edges.size() > N-1) { pos = false; return; }
            s[p.second]='0';
            for (int j=0; j < N; j++) {   // for each eventual child from p.second
                if (adj[p.second][j]=='0') continue;
                if (adj[node][j]=='0') {
                    pos = false; return;
                } s[j]='0';
            }
        }
    }
}

void dfs(int node) {
    visited[node] = true;
    total_visited++;
    for (int i : adj2[node]) {
        if (!visited[i]) dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        cin >> N;

        pos = true;
        sorted.clear();
        adj.clear(); adj.resize(N);
        all_edges.clear();
        for (int i=0; i < N; i++) {
            cin >> adj[i];
            int cnt = 0;
            for (int j=0; j < N; j++) {
                if (i==j) {
                    if (adj[i][j]=='0') { pos = false; break; }
                    adj[i][j]='0';
                } else if (adj[i][j]=='1') {
                    cnt++;
                }
            } sorted.push_back({cnt, i});
        } sort(sorted.rbegin(), sorted.rend());     // g -> l

        for (int i=0; i < N; i++) {
            if (!pos) break;
            create_edges(i);
        }

        if (!pos) { cout << "No\n"; continue; }

        // check if it's actually a tree
        adj2.clear(); adj2.resize(N);
        visited.clear(); visited.resize(N, false);
        total_visited = 0;
        for (auto& p : all_edges) {
            adj2[p.first].push_back(p.second);
            adj2[p.second].push_back(p.first);
        }
        dfs(0);

        if (!pos || all_edges.size() != N-1 || total_visited != N) {
            cout << "No\n"; continue;
        }

        cout << "Yes\n";
        for (auto& p : all_edges) cout << p.first+1 << ' ' << p.second+1 << '\n';
    }
}