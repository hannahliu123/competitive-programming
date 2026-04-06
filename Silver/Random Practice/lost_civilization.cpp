// CF - A1. Lost Civilization (Easy Version) - R1300

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        // SOLUTION 1: left -> right (greedily merging elements to a "parent")
        // int ans = 1;
        // int start = a[0];
        // for (int i{1}; i < N; i++) {
        //     if (a[i] <= start || a[i] > a[i-1]+1) {
        //         start = a[i];
        //         ans++;
        //     }
        // }

        // SOLUTION 1: right -> left (checking if each element could've been a parent of elements after)
        // this solution essentially tracks the solution for i to the end for each value of i.
        // it works because it always removes an item from the stack if it could've come from
        // a parent elements (by checking if the curr elem could be the parent of any items)
        // after it (previously visited). only checking the top of the stack is enough because
        // you can only add x+1 directly after an element x (so you couldn't have a gap between
        // x and x+1 unless the items in that gap were children of some other element in the gap
        // and would all cancel out). 
        stack<int> s{};
        for (int i{N-1}; i >= 0; i--) {
            while (!s.empty() && s.top()==a[i]+1) {
                s.pop();
            } s.push(a[i]);
        }
        int ans = s.size();

        cout << ans << endl;
    }
}
