// B

#include <bits/stdc++.h>
using namespace std;

int main() {
    string T, U;
    cin >> T >> U;

    int lenT = T.length();
    int lenU = U.length();
    
    bool works{true};
    for (int i{0}; i <= lenT-lenU; ++i) {
        works = true;
        for (int j{0}; j < lenU; ++j) {
            if (T[j+i] == U[j] || T[j+i] == '?') continue;
            else {
                works = false;
                break;
            }
        } if (works) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
