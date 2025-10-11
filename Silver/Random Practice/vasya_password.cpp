// CF - A. Vasya And Password - R1200

// Start: 3:48
// End: 4:20        32 mins

// Kinda scared I read the question wrong cos of how straightforward it was...

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string s;
        cin >> s;

        int lc{0}, uc{0}, d{0};
        for (int i{0}; i < s.length(); ++i) {
            int hei = (int)s[i];
            if ((int)s[i] >= 65 && (int)s[i] <= 90) uc++;
            else if ((int)s[i] >= 97 && (int)s[i] <= 122) lc++;
            else if ((int)s[i] >= 48 && (int)s[i] <= 57) d++;
        }

        if (lc > 0 && uc > 0 && d > 0) {
            cout << s << '\n';
            continue;
        } else if (lc == 0) {
            if (uc == 0) {      // lc & uc
                s[0] = 'A';
                s[1] = 'a';
            } else if (d == 0) {    // lc & d
                s[0] = '1';
                s[1] = 'a';
            } else {    // only lc
                for (int i{0}; i < s.length(); ++i) {
                    if ((int)s[i] >= 65 && (int)s[i] <= 90) {   // uppercase
                        if (uc > 1) {
                            s[i] = 'a';
                            break;
                        }
                    } else if ((int)s[i] >= 48 && (int)s[i] <= 57) {  // digit
                        if (d > 1) {
                            s[i] = 'a';
                            break;
                        }
                    }
                }
            }
        } else if (uc == 0) {
            if (d == 0) {       // uc & d
                s[0] = 'A';
                s[1] = '1';
            } else {    // only uc
                for (int i{0}; i < s.length(); ++i) {
                    if ((int)s[i] >= 97 && (int)s[i] <= 122) {   // lowercase
                        if (lc > 1) {
                            s[i] = 'A';
                            break;
                        }
                    } else if ((int)s[i] >= 48 && (int)s[i] <= 57) {  // digit
                        if (d > 1) {
                            s[i] = 'A';
                            break;
                        }
                    }
                }
            }
        } else if (d == 0) {    // only d
            for (int i{0}; i < s.length(); ++i) {
                if ((int)s[i] >= 65 && (int)s[i] <= 90) {   // uppercase
                    if (uc > 1) {
                        s[i] = '1';
                        break;
                    }
                } else if ((int)s[i] >= 97 && (int)s[i] <= 122) {  // lowercase
                    if (lc > 1) {
                        s[i] = '1';
                        break;
                    }
                }
            }
        }

        cout << s << '\n';
    }
}
