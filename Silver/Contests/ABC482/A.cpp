#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int cnt = 0;
    for (auto& i : s) {
        if (i=='o') {
            cnt++;
        }
    }

    cout << (cnt%2==1? "odd": "even") << '\n';
}