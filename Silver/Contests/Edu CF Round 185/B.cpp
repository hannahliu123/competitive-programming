// Problem B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        long long pos = 0;
        long long total = 0;
        for (int i{0}; i < N; ++i) {
            int x;
            cin >> x;
            pos += x;
            if (x > 0) total++;
        }

        if (pos == N) cout << 1 << endl;
        else {  // pos > 
            cout << min(pos - (N-1), total) << endl;
        }
    }
}
