// CF - C. Wrong Addition - R1200

// Start: 2:14
// End: 2:49        35 mins

// Had to do some debugging but i got it :)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string a, sum;
        cin >> a >> sum;

        int a_i{int(a.length())-1}, s_i{int(sum.length())-1};
        vector<int> b{};
        bool possible = true;
        while (a_i >= 0 && s_i >= 0) {
            int a_digit = a[a_i--] - '0';
            int s_digit = sum[s_i--] - '0';

            if (a_digit > s_digit) {
                if (s_i >= 0) {
                    if (sum[s_i]- '0' == 0) {
                        possible = false;
                        break;
                    } else {
                        s_digit += (sum[s_i--] - '0')*10;
                        if (s_digit - a_digit >= 10) {
                            possible = false;
                            break;
                        }
                    }
                }
                else {
                    possible = false;
                    break;
                }
            }

            b.push_back(s_digit - a_digit);
        }

        if (s_i < 0 && a_i >= 0) possible = false;
        else if (a_i < 0 && s_i >= 0) {
            while (s_i >= 0) b.push_back(sum[s_i--] - '0');
        }

        if (possible) {
            bool leading_zero = true;
            for (int i{int(b.size())-1}; i >= 0; --i) {
                if (leading_zero && b[i] != 0) leading_zero = false;
                if (!leading_zero) cout << b[i];
            } 
            
            if (leading_zero) cout << 0;
            cout << '\n';
        } else cout << -1 << '\n';
    }
}
