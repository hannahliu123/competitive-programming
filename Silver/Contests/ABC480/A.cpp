#include <bits/stdc++.h>
using namespace std;

int main() {
    char a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a=='A') {
        if (d=='D') cout << "No\n";
        else cout << "Yes\n";
    } else if (b=='A') {
        if (c=='D') cout << "No\n";
        else cout << "Yes\n";
    } else if (c=='A') {
        if (b=='D') cout << "No\n";
        else cout << "Yes\n";
    } else if (d=='A') {
        if (a=='D') cout << "No\n";
        else cout << "Yes\n";
    }
}