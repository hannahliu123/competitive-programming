// CF - E. Graph Composition - R1500

// bruh i understood it wrong the first time but then i spent
// hours upon hours on this stoopid problem and i dinally got it
// omg im actually so dead rn i wanna punch this problem and 
// okay lets stop there. i did some relaly bad implementation the
// first time around but it was so so so sketchy and then i couldn't
// debug it when it went wrong. i ended up looking at the editorial 
// but i spend at least 3 hours staring at this thing omg.

// lesson learned never spend more than 1.5 hrs on a problem bc i 
// seriously start going insane afterwards. next time i should just 
// take a break and do something else then come back to it maybe even
// a day later. this problem should NOT have been so hard at all but
// i need to realize that i was looking for connected areas. i should
// develop a better plan on paper before i jump into implementation.

// this solution is pretty straightforward and it's basically just dfs.
// the logic is slightly odd cos ive never rly done a problem like this,
// but that should be expected. i think next time i need to solve more
// graph problems. i had an era where i focused on that a lot and i
// think i need to go back to that era. ik there will def be at least
// one graph problem for usaco silver and prob a binary serach one too
// so uh i gotta lock in. i also havent done prefix sums or two pointers
// in a while. i nede to do more usaco specific problems and not just 
// random cf ones bc i always make some sketchy greedy solution.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjG;
vector<vector<int>> adjF;
vector<int> comp;  // index of connected component
vector<bool> visitedF;
int ans;

void dfsG(int node, int c) {
    comp[node] = c;
    for (auto i : adjG[node]) {
        if (comp[i] == 0) {
            dfsG(i, c);
        }
    }
}

void dfsF(int node) {
    visitedF[node] = true;
    for (auto i : adjF[node]) {
        if (!visitedF[i]) {
            if (comp[i] != comp[node]) {    // get rid of this edge
                ans++;
            } else {    // keep this edge
                dfsF(i);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, M1, M2;
        cin >> N >> M1 >> M2;

        adjF.clear(); adjF.resize(N);
        adjG.clear(); adjG.resize(N);
        comp.clear(); comp.resize(N, 0);
        visitedF.clear(); visitedF.resize(N, false);
        for (int i{0}; i < M1; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adjF[u].push_back(v);
            adjF[v].push_back(u);
        } for (int i{0}; i < M2; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adjG[u].push_back(v);
            adjG[v].push_back(u);
        }

        ans = 0;
        int comp1 = 0, comp2 = 0;
        for (int i{0}; i < N; ++i) {
            if (comp[i] == 0) {
                comp1++;
                dfsG(i, i+1);
            } if (!visitedF[i]) {
                comp2++;
                dfsF(i);
            }
        }
        
        ans += comp2-comp1;

        cout << ans << endl;
    }
}
