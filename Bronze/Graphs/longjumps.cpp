// CF - 1472C

// Pretty straightforward (until I reached my memory limit)
// Fixed the memory limit, but now I exceeded the time limit D:

// OHHH this is the kind of problem where the order in which I iterate over the
// array can reduce iterations. If I iterated over the array backwards and added
// the "final" value to another array, I would've been able to only use one for
// loop and no while loops. Then I would've had calculated the max value for 
// each index starting from the right, and I could add that value to any index
// that needs it to get its max (you get what i mean... hopefully)

// Next time I encounter a problem where I'm calculating a maximum value based
// on other calculations, I need to remember that I should think about what
// order I'm using to calculate the values. I should start with the smaller
// values so I can just add it onto the bigger values, reducing any redundant
// loops.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t{0}; t < T; ++t) {
        int N;
        cin >> N;

        vector<int> a(N);
        for (int i{0}; i < N; ++i) {cin >> a[i];}

        vector<int> totals(N);
        for (int i{N-1}; i >= 0; --i) {
            totals[i] = a[i];
            if (i+a[i] < N){
                int num = totals[i+a[i]];
                totals[i] += totals[i+a[i]];
            }
        }

        int ans{0};
        for (int i{0}; i < N; ++i) {
            ans = max(ans, totals[i]);
        }

        cout << ans << '\n';
    }
}
