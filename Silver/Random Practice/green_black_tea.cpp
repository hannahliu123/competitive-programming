// CF - D. Green and Black Tea - R1500

// Start: 10:00
// End: 10:20       20 mins!

// This was from 9 years ago so it's probably easier than typical R1500
// problems but i think i needed an ego boost... uh i might try moving
// up to 1600 tho and see how it goes. Um so the editorial barely explains
// anything but i think my solution makes a lot of sense so yipepeppep

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, A, B;
    cin >> N >> K >> A >> B;
    
    int mx = max(A, B);
    int mn = min(A, B);
    int k = mx/(mn+1);
    int rem = mx % (mn+1);

    if ((rem > 0? k+1 : k) > K) cout << "NO";
    else {
        char t1;
        char t2;
        if (mx == A) {
            t1 = 'G';
            t2 = 'B';
        } else {
            t1 = 'B';
            t2 = 'G';
        }

        for (int i{0}; i < mn+1; ++i) {
            int rep = k;
            if (rem > 0) rep++;
            for (int i{0}; i < rep; ++i) cout << t1;
            rem--;

            if (i != mn) cout << t2;
        }
    }
}
