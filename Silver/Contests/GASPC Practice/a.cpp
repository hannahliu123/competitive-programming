// It's Hot in Here

// wow i can't beleive this

#include <bits/stdc++.h>
using namespace std;

int main() {
    double temp; cin >> temp;
    char unit; cin >> unit;
    char desired; cin >> desired;

    double ans = 0;
    if (unit == 'F') {
        if (unit == 'C') {
            ans = (temp - 32) * 5.0/9.0;
        } else {    // K
            ans = (temp - 32) * 5.0/9.0 + 273.15;
        }
    } else if (unit == 'C') {
        if (unit == 'F') {
            ans = (temp * 9.0/5.0) + 32;
        } else {    // K
            ans = temp + 273.15;
        }
    } else {    // K
        if (unit == 'C') {
            ans = temp - 273.15;
        } else {    // F
            ans = (temp - 273.15) * 9.0/5.0 + 32;
        }
    }

    ans = floor(ans*100) / 100.0;
    cout << fixed << setprecision(2) << ans;
    return 0;
}
