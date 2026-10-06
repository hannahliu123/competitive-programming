// D. Giving Awards - R2000

// the other solution is just greedy and lowkey pmos because i thought fs this was a pure
// graph problem. basically you can start with any arbitraty answer, say 12345...N. Then
// going from left to right, if there is an ab next to eachother, take the b and keep
// moving it left (towards the front) until it (as b) is not part of an invalid ab. So as
// you move from left to right, the prefix of the answer will be valid. bruh this is so 
// straightforward because you can just greedily place nodes. and inserting a node between
// a working configuration won't make anything invalid either as long as the inserted node
// is valid

// oh and also because we know the input data will not contain pairs p, q and q, p
// simultaneously, there will never be a case where there's no solution. In the worse
// case, if 1 has a debt to all other nodes, 1 must be placed at the end. Then 2 can only
// have depts to all other nodes excluding 1, so 2 can be placed 2nd to last right before
// 1. Then so on such that there can always be a solution even if you have the maximum
// possible debt relationships

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    set<pair<int,int>> s;
    for (int i=0; i < M; i++) {
        int a, b; cin >> a >> b;
        s.insert({a,b});
    }

    vector<int> ans(N);
    for (int i=0; i < N; i++) ans[i] = i+1;
    for (int i=1; i < N; i++) {
        int j = i;
        while (j>0 && s.count({ans[j-1], ans[j]})) {
            int temp = ans[j-1];
            ans[j-1] = ans[j];
            ans[j] = temp;
            j--;
        }
    }

    for (auto& i : ans) cout << i << ' ';
    cout << '\n';
}