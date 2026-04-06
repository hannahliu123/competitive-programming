// CF - A2. Lost Civilization (Hard Version) - R1700

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        stack<pair<int,int>> s{};
        long long ans = 0;  // sum of answers for all subsequences of all sequences starting from 0...N-1
        long long prev = 0;     // the answer for all subsequences starting at i
        int val = 1;    // number of subsequences that start from i
        for (int i{N-1}; i >= 0; i--) {
            while (!s.empty() && s.top().first==a[i]+1) {
                // current a[i] is a parent of an element in the stack (previously visited)
                // the previously visited item is no longer a parent (it's contibution is combined into that of its parent)
                prev -= s.top().second;
                s.pop();
            }
            s.push({a[i], val});    // current element (new parent)
            prev += val;
            ans += prev;
            val++;
        }

        cout << ans << endl;
    }
}
