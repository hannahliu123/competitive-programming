// Problem A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        
        int mn{9};
        for (int i{0}; i < s.length(); ++i) {
            if (s[i] - '0' < mn) mn = s[i] - '0';
        }

        cout << mn << endl;
    }
}
