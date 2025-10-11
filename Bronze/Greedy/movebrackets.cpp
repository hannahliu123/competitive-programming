// CF - 1374C, R1000

// pretty easy :) OMG my solution is like really similar to the editorial
// but it might be EVEN BETTER!!! YIPEPEPPEPEPEEE

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int length; // even number
        string s;
        cin >> length >> s;

        int count{0};
        int ans{0};
        for (int i{0}; i < length; ++i) {
            if (s[i] == '(') ++count;
            else --count;
            ans = min(ans, count);
        }
        cout << -1*ans << '\n';
    }
}
