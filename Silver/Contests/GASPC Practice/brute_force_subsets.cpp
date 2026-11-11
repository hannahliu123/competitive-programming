#include <bits/stdc++.h>
using namespace std;

int main() {
    int N=5;
    vector<int> v(N, 1);
    for (int i=0; i < (1<<N); i++) {
        // i is our bitmask
        cout << "Bitmask: " << i << '\n';
        for (int j=0; j < N; j++) {
            if (i & (1<<j)) {
                // bit is turned on
                cout << j << ' ';
            }
        } cout << '\n';
    }
}