// B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> p(N);
        for (auto& i : p) cin >> i;

        int l = -1, r = -1, x = -1;
        for (int i{0}; i < N; ++i) {
            if (x == -1) {
                if (p[i] == N-i) {
                    cout << p[i] << ' ';
                } else {
                    l = i;
                    x = N-i;
                }
            } else if (p[i] == x) {
                r = i;
                break;
            }
        }

        if (l == -1) {
            cout << endl;
            continue;
        }
        for (int i{r}; i >= l; --i) cout << p[i] << ' ';
        for (int i{r+1}; i < N; ++i) cout << p[i] << ' ';
        cout << endl;
    }
}
