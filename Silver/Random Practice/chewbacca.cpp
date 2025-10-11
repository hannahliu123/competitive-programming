// CF - A. Chewbaсca and Number - R1200

// Start: 1:42
// End: 2:11

// Only took so long because the problem was so unclear. Whatever im not gonna try to explain
// how dumb it is

#include <bits/stdc++.h>
using namespace std;

int main() {
    string x;
    cin >> x;

    for (int i{0}; i < x.length(); ++i) {
        int num = x[i] - '0';
        if (num >= 5) {
            if (num == 9 && i == 0) cout << num;
            else cout << 9 - num;
        } else {
            cout << num;
        }
    }

    cout << endl;
}
