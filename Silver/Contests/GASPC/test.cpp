#include <bits/stdc++.h>
using namespace std;

int main() {
    char c; cin >> c;
    string trash; getline(cin, trash);
    string s;
    getline(cin, s);
    char c2;
    if (c <= 90) c2 = c+32;
    else c2 = c-32;
    
    int cnt = 0;
    for (int i{0}; i < (int)s.size(); i++) {
        if (s[i] == c || s[i] == c2) cnt++;
    }
    cout << cnt;
    return 0;
}
