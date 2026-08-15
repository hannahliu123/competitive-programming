// A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;

    if (a+b==9 || a-b==9 || a*b==9 || (a%b==0 && a/b==9)) cout << "Nine\n";
    else cout << "Nein\n";
}