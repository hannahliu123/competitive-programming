// B

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    set<int> seen{};
    bool pos = true;
    int total = 0;
    while (total != 1) {
        total = 0;
        for (int i{0}; i < s.length(); ++i) {
            int val = s[i]-'0';
            int x = val*val;
            total += x;
        }
        if (seen.count(total)) {
            pos = false;
            break;
        } else {
            seen.insert(total);
            s = to_string(total);
        }
    }

    if (pos) cout << "Yes" << endl;
    else cout << "No" << endl;
}
