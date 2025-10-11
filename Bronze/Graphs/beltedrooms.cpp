// CF - 1428B - R1200

// Start: 5:15
// End: 6:05    50 mins

// IM SUPER PROUD OF THIS ONEEEEE. K the solution is very similar except insead of 
// setting ans to the amount of "-"s then adding an extra if the next one is not off, 
// the just directly calculated the answer from zero. So if a point had a "-" at or
// after it, then it added 1 to the answer. Also instead of the looping around thing,
// they just added the first letter to the end of the string (big brainnnnnn)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;  // rooms
        string s;   // > clockwise, < counterclockwise, - off
        cin >> n >> s;

        int cw = 0, ccw = 0, off = 0;
        vector<bool> offs(n);
        for (int i{0}; i < n; ++i) {
            if (s[i] == '>') ++cw;
            else if (s[i] == '<') ++ccw;
            else {
                ++off;
                offs[i] = true;
            }
        }

        if (cw == 0 || ccw == 0) cout << n << '\n';
        else {
            int ans{off};
            for (int i{0}; i < n; ++i) {
                if (offs[i] == true) {
                    int temp = (offs[i]+1)%n;
                    if (offs[(i+1)%n] == false) {++ans;} 
                }
            } cout << ans << '\n';
        }
    }
}

// TLE test case 4
