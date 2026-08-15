// D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q, V; cin >> Q >> V;

    priority_queue<int> pq{};
    int t0 = -1;
    while (Q--) {
        int type, t; cin >> type >> t;
        if (t0==-1) t0=t;
        int time_diff = t-t0;
        if (type==1) {  // plug
            int w; cin >> w;
            pq.push(w-time_diff);
        } else {    // unplug highest or -1
            if (pq.empty()) cout << -1 << '\n';
            else {
                cout << min(V, pq.top()+time_diff) << '\n';
                pq.pop();
            }
        }
    }
}