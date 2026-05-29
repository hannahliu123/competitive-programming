// USACO 2016 February Contest, Silver
// Problem 3. Milk Pails

// i have absolutely no idea how this problem could be related to floodfill. I tried
// to implement a greedy solution using the assumtion that there are only certain
// ways to create new combinations of pail values. However, A greedy formula struggles
// to capture every single one of these branching decision paths, leading to wrong
// answers on complex test cases. Because the bounds are so small, this is a sign that
// we can brute force through all senarios for K moves, and a great way to do that is
// to use a graph where eath state is a node (a state is just a pair with the value of
// each bucket) and there are 6 operations you can do at each node (edges): empty,
// either, fill either, or dump into eachother. bucket 1 can range from 0 to X whereas
// bucket 2 can range from 0 to Y, so there are (X+1)*(Y+1) total combinations of
// nodes/states. Thus the max number of combinations is 101*101 = 10201. Knowing this,
// we can perform dfs or bfs on the graph, but notice how we don't explicitly have an
// adjacency list or a set of pre-known nodes. Thus, this is actually more like
// floodfill than dfs/bfs because we are just calling on 6 edge options for every node.

// Ok now that you understand the graph representation, it's also important to realize
// that if you go with a dfs/floodfill (essentially the same thing in this case)
// implementation, you would result in a O(XYK) time complexity because for each state
// (we have about X*Y total states), you can visit it once for every single K value
// possible. This is becase dfs means you go as deep as possible down edges, so you
// will arrive at certain states after many operations (large K value). Then when you
// revisit that state at an earlier K value, your visited array will see the node as
// already visited, causing you to skip it, even though going down that path could've
// resulted in more desireable combinations. So, you would need a 3d visited array
// to track x, y, and k. 

// HOWEVER, this is when bfs come in handy bc bfs explores the graph level by level
// (so grouped by smallest to largest k values). thus, it always hits the earliest 
// occurance of each state first so we can have a clean O(XY) time complexity.

// LESSON/KEY TAKEAWAY: If there's ever a similar problem that involves having states
// that can be updated in a limited number of ways to form different combinations of
// some value, it's likely that it can be represented as a graph to brute force your
// way through all possible combinations of actions

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int X, Y, K, M; cin >> X >> Y >> K >> M;

    int ans = M;
    vector<vector<bool>> visited(101, vector<bool>(101, false));
    queue<vector<int>> q{};
    q.push({0,0,0});
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        int x = v[0], y = v[1], k = v[2];
        if (visited[x][y]) continue;

        ans = min(ans, abs(M-(x+y)));
        visited[x][y] = true;

        // try all 6 operations
        if (k==K) continue;
        q.push({0, y, k+1});
        q.push({x, 0, k+1});
        q.push({X, y, k+1});
        q.push({x, Y, k+1});
        int pourX = min(y, X-x);    // amount poured into X
        q.push({x+pourX, y-pourX, k+1});
        int pourY = min(x, Y-y);
        q.push({x-pourY, y+pourY, k+1});
    }

    cout << ans << endl;
}
