// CF - E. Round Dance - R1600

// Start: 9:52
// End: 10:34       42 mins

// omg im so happy i got this so quickly. AND it's a 1600 problem so 
// yayayyay!! I actually used dfs lol so im super proud of that but
// ig i knew it was a graph problem but i think i would've been able
// to figure it out anyways :D

// yep this was a connected components problem. so i think this was
// a bamboo problem?? but ive never rly heard of that term. ig its kinda
// like a type of graph eg a tree but wtv. editorial used bfs but i
// like dfs more lol so imma go with that hehe. i like my implementation
// this time bc usually i mess up cc implementations so much. i couldve
// made the loops logic better but i was like building upon it soooo
// ill take it. i think a reason why i got this so quickly was bc
// the test cases were rly solid.

#include <bits/stdc++.h>
using namespace std;

vector<set<int>> adj;
vector<int> cc;
int loops;
bool looped;

void dfs(int node, int prev, int c) {
    cc[node] = c;
    for (int i : adj[node]) {
        if (looped) return;
        if (cc[i] == c && i != prev) {  // loops back
            loops++;
            looped = true;
        } else if (cc[i] == -1) dfs(i, node, c);  // haven't visited
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int N;
        cin >> N;
        adj.clear();
        adj.resize(N);
        cc.clear();
        cc.resize(N, -1);
        loops = 0;
        looped = false;

        for (int i{0}; i < N; ++i) {
            int x;
            cin >> x;
            adj[i].insert(--x);
            adj[x].insert(i);
        }

        int c = 0;  // total sections
        for (int i{0}; i < N; ++i) {
            if (cc[i] == -1) {
                looped = false;
                dfs(i, -1, ++c);
            }
        }

        cout << (c>loops? loops+1: loops) << ' ' << c << endl;
    }
}
