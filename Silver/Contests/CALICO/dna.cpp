#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        for (auto& ch : s) {
            if (ch=='A') cout << 'T';
            if (ch=='T') cout << 'A';
            if (ch=='C') cout << 'G';
            if (ch=='G') cout << 'C';
        } cout << '\n';
    }
}