// CF - B. Books - R1400

// Start: 8:55
// End: 9:17        22 mins (cos I couldn't figure out the implementation lol)

// This is my implementation without actually learning how to implement two 
// pointers

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<int> a(N);
    for (auto& i : a) cin >> i;

    int max_books{0};
    int i{0}, j{0}, time{0};
    // while (j != N) {
    //     if (time + a[j] <= T) {
    //         time += a[j];
    //         j++;
    //     } else {
    //         max_books = max(max_books, j-i);
    //         time -= a[i];
    //         i++;
    //     }
    // } max_books = max(max_books, j-i);

    while (i < N && j < N) {
        while (j < N) {     // add as many books as possible
            time += a[j++];
            if (time > T) {     // undo if time surpasses max
                time -= a[--j];
                break;          // move on to left i (left) value
            }
        }
        
        max_books = max(max_books, j-i);    // update answer
        time -= a[i++];
        // subtract left because we're moving to the next value of i
    }

    cout << max_books << endl;
}
