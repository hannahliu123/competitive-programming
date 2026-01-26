// USACO 2026 First Contest, Silver
// Problem 2. Mooclear Reactor

// i was lowkey just lost lost in this problem. i kinda recognized that it was
// a graph, but i didn't really know where to go from there. i was just lost
// because i didn't know how to solve those layered systems of equations. OHHH
// okay so i got to the part where we separate connected components then label
// the starting node as x and write everyting in terms of x. then i got stuck
// because i tried to solve for x and didnt realize that having infinite solutions
// was possible. in reality, you just take the expression of x for each node
// then transform it to a range x can be within in order for that node (reactor)
// to still work. then once you have a ton of ranges of x, you just use a 
// difference array to see which x value is most desireable for each connected 
// component. then u sum up everything from each CC. okay wait now i just realized
// there are three different possibilities. you can either find a CC with one 
// solution, no solution, or infinite solutions. because of this, you need to 
// constantly be on the lookout for one/no solutions. Only if there are infinite
// solutions should you implement a difference array. 

// let's look at time complexity then. first we create the graph (adjacency list)
// in O(N) time and we can peform dfs to find all connected components in O(N+M).
// for each connected component we can select the first node as the start one and
// rewrite all other nodes in terms of that first node. then for each of the ranges
// of each node in a CC, we collect the start and end possible values then use a 
// difference array in O(N) time where N is the size of the CC. we will only include
// each node at most once. and so once we find the number of nodes we can satisfy
// by chosing a start node value of say x, we add that to the answer then continue
// processing all other connected components!

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;  // destination, sum
vector<pair<long long,int>> visited;    // constant, +/-x
vector<int> cc;    // all reactors in a cc
int sols;  // -1=none, 0=inf, 1=one
long long x;

void dfs(int node, pair<long long,int> val) {
    visited[node] = val;
    cc.push_back(node);
    for (auto& i : adj[node]) {
        long long sum = i.second;
        long long f = val.first;
        int s = val.second;
        if (visited[i.first] == make_pair(0LL,0)) {
            dfs(i.first, {sum-f,(s==1? -1 : 1)});
        } else if (sols == -1) continue;    //  just visit all the other nodes
        else {
            long long right = sum - (visited[i.first].first + f);
            int coef = visited[i.first].second + s;
            if (coef==0 && right==0) {
                continue;   // infinite solutions
            } else if ((coef==0 && right!=0LL) || (right%coef != 0LL)) {
                sols = -1;   // no solution
            } else {
                if (sols == 1 && x != right/coef) {
                    sols = -1;  // contradiction!!
                } else {
                    sols = 1;   // one solution
                    x = right/coef;
                }
            }
        }
    } if (sols == -1) return;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        vector<int> l(N);
        for (auto& i : l) cin >> i;
        vector<int> r(N);
        for (auto& i : r) cin >> i;

        adj.clear(); adj.resize(N);
        visited.clear(); visited.resize(N, {0,0});
        for (int i{0}; i < M; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            x--; y--;
            adj[x].push_back({y,z});
            adj[y].push_back({x,z});
        }

        bool pos = true;
        int ans = 0;
        for (int i{0}; i < N; ++i) {
            if (visited[i] == make_pair(0LL,0)) {
                sols = 0; x = 0LL;
                cc.clear();
                dfs(i, {0LL,1});

                if (sols == 1) {    // check how many reactors work
                    for (auto& j : cc) {
                        long long val = visited[j].first + x*visited[j].second;
                        if (val >= l[j] && val <= r[j]) ans++;
                    }
                } else if (sols == 0) {  // find most desirable x val
                    vector<pair<long long, int>> sweep{};   // bound, +/-1
                    for (auto& j : cc) {    // update sweep
                        long long left = l[j];
                        long long right = r[j];
                        if (visited[j].second == 1) {
                            left -= visited[j].first;
                            right -= visited[j].first;
                        } else {    // -1
                            left = -1*(r[j]-visited[j].first);
                            right = -1*(l[j]-visited[j].first);
                        }
                        sweep.push_back({left,1});
                        sweep.push_back({right+1,-1});
                    }
                    sort(sweep.begin(), sweep.end());   // l -> g
                    int mx = 1;
                    for (int j{1}; j < sweep.size(); ++j) {
                        sweep[j].second += sweep[j-1].second;
                        mx = max(mx, sweep[j].second);
                    } ans += mx;
                } else {
                    pos = false;
                    break;
                }
            }
        }

        if (pos) cout << ans << endl;
        else cout << -1 << endl;
    }
}
