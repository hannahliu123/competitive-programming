// CF - B. Badge - R1000

// Start: 10:53
// End: 11:20       27 mins

// lol in my defense i got the O(N) solution soooo

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> p(N);
    set<int> students;
    for (int i=0; i < N; i++) {
        cin >> p[i]; p[i]--;
        students.insert(p[i]);
    }

    vector<int> start{};
    for (int i=0; i < N; i++) {
        if (students.count(i) == 0) start.push_back(i);
    }

    vector<int> ans_loc(N, -1);
    vector<int> ans{};
    int idx = 0;
    for (auto& x : start) {
        int i=p[x], j=p[p[x]];
        while (i != j) {
            i = p[i];
            j = p[p[j]];
        } j = x;
        ans_loc[j] = idx;
        while (i != j) {
            i = p[i];
            j = p[j];
            ans_loc[j] = idx;
        }
        ans.push_back(i);   // start of cycle
        idx++;
    }

    for (int i=0; i < N; i++) {
        if (ans_loc[i] == -1) cout << i+1 << ' ';
        else cout << ans[ans_loc[i]]+1 << ' ';
    }
}
