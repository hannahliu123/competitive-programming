// B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    vector<int> cubes{0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i{0}; i < m; ++i) {
            int w, l, h;
            cin >> w >> l >> h;

            bool possible{true};
            if (w < cubes[n] || l < cubes[n] || h < cubes[n]) {
                possible = false;
            } else {
                h -= cubes[n];
                if (h < cubes[n-1]) {
                    if (l > w) l -= cubes[n];
                    else w -= cubes[n];
                    if (l < cubes[n-1] || w < cubes[n-1]) possible = false;
                }
            }
            
            if (possible) cout << "1";
            else cout << "0";
        } 

        cout << '\n';
    }
}
