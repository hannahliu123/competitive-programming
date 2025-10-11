#include <bits/stdc++.h>
using namespace std;

// I could've implemented this more efficiently by just using addition/subtraction
// directly on the indexes. Either way, they both work so whatever

int main() {
    int N;
    cin >> N;

    int prev2 = -1;
    int prev1 = -1;
    for (int i{0}; i < N; ++i) {
        int curr;
        cin >> curr;
        if (prev2 == prev1 && prev1 == curr) {
            cout << "Yes" << endl;
            return 0;
        }
        prev2 = prev1;
        prev1 = curr;
    }

    cout << "No" << endl;
    return 0;
}
