// B

// this is pretty much just a greedy problem. the editorial explains that a large number
// will always find a way to be reduced and once a number reaches below 100, it will always
// hit either 1 or 4. my approach was just to check if there was a repeated cycle which
// also worked and i think mine is easier and more logical because the only reason it
// wouldn't hit 1 is if it keeps repeating someone. the only concern might be time 
// complexity but 2026 is too small

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
