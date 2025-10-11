// CF - C. Meme Problem - R1300

// Start: 8:55
// End: 9:21        26 mins! AHHHHH YIPEPEPPE

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int d;
        cin >> d;

        double lo{0}, hi{(double)d};    // for the bigger number
        bool possible = true;
        while (lo + 0.0000000001 < hi) {
            double mid = lo + (hi - lo) / 2;
            double b = d - mid;
            double product = mid*b;
            if (b > mid) {
                possible = false;
                break;
            } if (product-0.0000000001 < d && product+0.0000000001 > d) {
                hi = mid;
                break;
            } else if (product > d) lo = mid;
            else hi = mid;
        }

        if (possible) {
            cout << fixed << setprecision(9) << "Y" << ' ' << hi << ' ' << d-hi << '\n';
        } else cout << "N\n";
    }
}
