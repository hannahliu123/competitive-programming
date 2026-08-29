// im really proud i figured out this was related to dfs, because it does not at all seem
// like a graph problem. I think the fact that it gave us a really good test case helped
// a ton because i traced through the entire last test case to test if my algorithm
// worked and it helped me code out the implementation and check my work.

// okay ive been trying to understand how the editorial did it and this is just pointless.
// im too braindead for this. imo the editorial solution is worse than mine because it just
// tried to brute for the answer by looping through all possible sequences in lexicographical
// order until N, then seeing if ome value of A[N] satisfies the condition. theres some
// werid time complexity stuff to justify why this works, and the main realizaiton is that
// the sum of the first N-1 elements should always be <=K, so we aren't processing that many
// combinations. i guess if you think hard enough about this then intuitively it should
// be pretty efficient because you never go deep into an invalid solution, and if you do
// end up with N not working out, you just continue to backtrack and it doesn't waste that
// much time kinda? ig if i were truly stuck on a usaco constest i might try implementing
// this but i just hate problems with inexact time complexities

// anyways my approach to this problem was that we can notice how small N is (<=10), which
// indicates we can do some type of brute forcing/selection over the N slots. Also notice
// how it graciously tells us the total number of valid subsequences is < 3*10^5, which is
// very manageable. So, i thought if i can just get all the subsqueneces then sort them in
// O(xlogx) time, then we'll have the solution. to get the subsequeneces, it wa sjust a dfs
// approach (that lowkey took a while to implement) but in the end makes sense and is 
// relatively straightforward. the main idea is that you start with A[0]=K and everything
// else = 0. then you distribute some of the value from 1 to the other slots. then from
// those slots, you continue to distribute weights from 1 to any slot at or after the
// previous which guarentees no overlap. at every stage, a resulting vector is a valid 
// answer

#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int>> ans;

void dfs(vector<int>& v, int start) {
    ans.push_back(v);
    for (int i=start; i <= min(N,v[0]); i++) {
        vector<int> v1 = v;
        v1[0] -= i;
        v1[i-1]++;
        dfs(v1, i);
    }
}

int main() {
    cin >> N >> K;
    ans.clear();

    vector<int> a(N, 0);
    a[0] = K;
    dfs(a, 2);

    sort(ans.begin(), ans.end());
    for (auto& v : ans) {
        for (auto & i : v) cout << i << ' ';
        cout << '\n';
    }
}