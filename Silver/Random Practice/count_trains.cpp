// CF - G. Count the Trains - R1x00

// I read the editorial and im so happy I actually understand the solution.
// I'm gonna try to redo this problem on tuesday to see if i can redo it
// without looking at the editorial lol

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        vector<int> a(N); 
        set<int> tmp;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            if (tmp.empty() || a[i] < a[*tmp.rbegin()]) {
                tmp.insert(i);
            }
        }

        while (M--) {
            int k, d;
            cin >> k >> d;
            k--; a[k] -= d;
            auto it = tmp.upper_bound(k);
            it = prev(it);
            if (*it == k || a[*it] > a[k]) {
                tmp.insert(k);
            }
            
            while (true) {
                it = tmp.upper_bound(k);
                if (it != tmp.end() && a[*it] >= a[k]) {
                    tmp.erase(it);
                } else break;
            } cout << tmp.size() << " ";
        } cout << endl;
    }
}
