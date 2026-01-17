// C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string s;
        cin >> N >> s;

        int z=0;
        for (int i{0}; i < N; ++i) {
            if (s[i]=='0') z++;
        }

        vector<int> ans{};
        for (int i{0}; i < N; ++i) {
            if (i < z && s[i]=='1') ans.push_back(i);
            else if (i >= z && s[i]=='0') ans.push_back(i);
        }

        if (ans.size()==0 || z==0 || z==N) {
            cout << "Bob" << endl;
            continue;
        }

        cout << "Alice\n" << ans.size() << '\n';
        for (auto& i : ans) {
            cout << i+1 << ' ';
        } cout << endl;
    }
}
