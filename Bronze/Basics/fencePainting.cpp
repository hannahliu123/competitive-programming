#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    vector<bool> paint(100);
    int a;
    int b;
    int c;
    int d;
    cin >> a >> b >> c >> d;

    for (a; a < b; ++a) {paint[a] = true;}
    for (c; c < d; ++c) {paint[c] = true;}

    int painted{0};
    for (const auto& x : paint) {
        painted += x;
    }

    cout << painted;
}
