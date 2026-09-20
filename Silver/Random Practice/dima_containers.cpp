// C. Dima and Containers - R2000

// Start: 8:35
// End: 9:09            34 mins

// that was shockingly easy omg hm but okay that was from 13 years ago... literally
// just a simple greedy solution i thought i was missing something

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> ans(N, -1);
    vector<pair<int,int>> curr{};
    for (int i=0; i < N; i++) {
        int x; cin >> x;
        if (x==0) {
            sort(curr.rbegin(), curr.rend());   // g -> l
            ans[i] = min(3, (int)curr.size());
            for (int j=0; j < ans[i]; j++) {
                ans[curr[j].second] = -2;
            } curr.clear();
        } else {
            curr.push_back({x,i});
        }
    }

    vector<string> extract{"popStack", "popQueue", "popBack"};
    vector<string> add{"pushStack", "pushQueue", "pushBack"};
    int idx = 0;
    for (int i=0; i < N; i++) {
        if (ans[i] == -1) cout << "pushFront\n";
        else if (ans[i] == -2) {
            cout << add[idx] << '\n';
            idx++;
        } else {
            cout << ans[i];
            for (int j=0; j < ans[i]; j++) cout << ' ' << extract[j];
            cout << '\n';
            idx = 0;
        }
    }
}