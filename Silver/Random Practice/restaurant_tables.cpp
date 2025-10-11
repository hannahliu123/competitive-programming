// CF - A. Restaurant Tables - R1200

// Start: 4:22
// End: 4:36        14 mins (very easy... might move up to R1300)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;        // groups, 1-person tables, 2-person tables
    cin >> N >> A >> B;

    int occ1{0}, half2{0}, occ2{0};     // occ = fully occupied, half = half occupied
    int denied{0};
    for (int i{0}; i < N; ++i) {
        int group;
        cin >> group;

        if (group == 1) {   // 1 person
            if (occ1 < A) occ1++;
            else if (occ2 + half2 < B) {
                half2++;
            } else if (half2 > 0) {
                occ2++;
                half2--;
            } else denied++;
        } else {    // 2 people
            if (occ2 + half2 < B) occ2++;
            else denied += 2;
        }
    }

    cout << denied << endl;
}
