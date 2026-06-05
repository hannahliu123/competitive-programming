// CF - E. Replace the Numbers - R1900

// this problem is actually very straightforward if you just process the
// queries from the end to the beginning and track what each number would
// become. i was trying to see if i could use binary search or graphs to
// figure out this problem when it was just so stupidly simple.

// The fact that each number could change its identity with more type 2
// operations as the queries are processed is a hint that going forward is 
// a wasteful or inefficient idea.

// As a rule of thumb, if a forward operation merges, overwrites, or destroys
// some state, going backward often does the exact opposite, usually preserving
// or resolving the state

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    
    vector<int> become(500001, -1);
    vector<int> ans{};
    vector<vector<int>> queries(q);
    for (int i=0; i < q; i++) {
        int type; cin >> type;
        int x; cin >> x;
        if (type == 1) queries[i] = {type,x};
        else {
            int y; cin >> y;
            queries[i] = {type,x,y};
        }
    }

    for (int i=q-1; i >= 0; i--) {
        int type = queries[i][0], x = queries[i][1];
        if (type == 1) {
            if (become[x] == -1) become[x] = x;
            ans.push_back(become[x]);
        } else {    // replace all x with y
            int y = queries[i][2];
            if (become[y] == -1) become[y] = y;
            become[x] = become[y];
        }
    }

    for (int i=ans.size()-1; i >= 0; i--) {
        cout << ans[i] << ' ';
    } cout << endl;
}