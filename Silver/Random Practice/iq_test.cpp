// CF - A. IQ test - R1300

// Start: 3:11
// End: 3:15        4 mins (BAHAHAH HOW WAS THIS 1300????)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int even{0}, odd{0}, even_index{-1}, odd_index{-1};
    for (int i{0}; i < N; ++i) {
        int x;
        cin >> x;

        if (x % 2 == 0) {
            even++;
            even_index = i;
        } else {
            odd++;
            odd_index = i;
        }
    }

    if (even > odd) cout << odd_index+1 << endl;
    else cout << even_index+1 << endl;
}
