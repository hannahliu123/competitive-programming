// Rotate and Shift REDO 

// ~2 hrs 0 mins (I didn't time it exactly)

// LETS FREAKING GO. THIS WAS SO POORLY PLANNED AND TOOK SO FREAKING LONG, BUT UHM I 
// SOMEHOW GOT IT! NOT RLY SOMETHING TO BE PROUD OF... BUT UH LET'S FINALLY READ THAT
// EDITORIAL HEH. Watch their solution be so freaking clean and simple...

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, T;    // cows, shifting positions, minutes
    cin >> N >> K >> T;

    vector<int> A(K);   // shifting positions
    vector<int> cows(N);
    for (int i{0}; i < K; ++i) cin >> A[i];
    for (int i{0}; i < N; ++i) cows[i] = i;

    int a{0};
    vector<int> ans(N);
    for (int i{0}; i < N; ++i) {
        int index = i+T;
        while (index >= N) index -= N;
        
        int gap = (a==K-1? N-A[a] : A[a+1]-A[a]);
        int num = (i-A[a]+(T%gap))+A[a];
        ans[index] = ((i-A[a]+(T%gap))%gap)+A[a];
        //ans[index] = ((i-A[a]+((i+T)%gap))%(gap))+A[a];

        if (i+1 >= A[a+1] && a < K-1) ++a;
    }

    for (int i{0}; i < N; ++i) {
        if (i > 0) cout << ' ';
        cout << ans[i];
    } cout << endl;
}
