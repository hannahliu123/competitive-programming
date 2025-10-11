// CF - C. Table Tennis Game 2 - R1200

// Start: 4:38
// End: 4:47        9 mins...

// Bruh okay im moving to R1300

#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, A, B;
    cin >> K >> A >> B;

    int wins1 = A/K, rem1 = A%K;
    int wins2 = B/K, rem2 = B%K;

    if (wins1 == 0 && wins2 == 0) cout << -1 << endl;
    else if (wins1 == 0) {
        if (rem2 == 0) cout << wins2 << endl;
        else  cout << -1 << endl;
    } else if (wins2 == 0) {
        if (rem1 == 0) cout << wins1 << endl;
        else  cout << -1 << endl;
    } else {
        cout << wins1 + wins2 << endl;
    }
}
