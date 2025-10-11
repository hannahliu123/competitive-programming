#include <bits/stdc++.h>
using namespace std;

// This solution works fine when the intervals are so small, but if the bounds
// were larger, I would need to figure out the formula to calculate this. Oh ok
// so i read the solution and it's just the total area - overlap. I feel like i
// would struggle to calculate that overlap, and i would just end up using if
// statements. Ig drawing it out and trying to make connections might get me there
// but like i would just have to practice this stuff more

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<bool> painted(100);

    for (int i{a}; i < b; ++i) {painted[i] = true;}
    for (int i{c}; i < d; ++i) {painted[i] = true;}

    int ans{0};
    for (bool paint : painted) {
        if (paint) ++ans;
    }

    cout << ans << endl;
}
