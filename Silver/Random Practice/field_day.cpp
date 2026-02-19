// USACO 2023 US Open Contest, Silver
// Problem 2. Field Day

// sooo i was so completely lost when I read this problem and i had no idea how
// to approach this without an N^2 solution. in reality, this was a part bfs part
// bitwise operators problem. Basically i did realize that there's no greedy
// solution. You just need to find an efficient way to calculate it by taking
// advantage of certain properties. One important thing to notice is that C <= 18.
// I didn't really know what that meant though. But coupled with the fact that 
// there are only two states (H and G), you can represent each string in binary and
// you can process every single possible combination because there are only 2^18
// possible combos! 2^18 is about 3*10^5, which is perfectly okay to process. 

// Then you had to realize that for each team, if you want to find another team
// that is as different as possible, you can represent that with a graph where each
// edge means that the two nodes it connects are different by one bit. 

// this final solution is somewhat of a brute force solution but instead of visiting
// every team for every team (N^2), you visit every single possible team (2^18) and
// determine its distance (number of changes) before reaching the inverse of one of
// given team nodes (so the final answer is c-dist). This logic is kinda confusing
// until you really think about it. 

// Each inverse represents changing a team by C bits (maximum). Starting from all 
// inverses, each time you change one bit (travel across an edge), you are subtracting
// the number of changes by 1 (going back towards the original team). When an inverse
// makes its way to any node (team combination), that distance is the number of bits
// changed compared to the original inverse of a team. the distance will be as small
// as possible, meaning the number of bits changed compared to the actual (non-inverse)
// of that team is as large as possible (C-dist). 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int C, N;
    cin >> C >> N;

    vector<int> teams(N);
    vector<int> dist(1<<C, 1000);
    queue<int> q;
    for (int i{0}; i < N; ++i) {
        string s; 
        cin >> s;
        int x = 0;  // team in binary (store the value)
        int inv = 0;    // inverse of x
        for (auto& c : s) {
            x = 2*x + (c=='G'? 1 : 0);
            inv = 2*inv + (c=='H'? 1 : 0);
        }
        teams[i] = x;
        dist[inv] = 0;
        q.push(inv);
    }
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i{0}; i < C; ++i) {
            int y = x ^ 1<<i;
            if (dist[y] == 1000) {
                q.push(y);
                dist[y] = dist[x] + 1;
            }
        }
    }

    for (int i{0}; i < N; ++i) {
        cout << C-dist[teams[i]] << '\n';
    }
}
