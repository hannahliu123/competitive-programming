// CF - B. Two Buttons - R1400

// Start: 8:41
// End: 9:15            34 mins (uhh i didn't use graphs at all wth)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;       // current, end goal
    cin >> N >> M;
    
    if (M <= N) {
        cout << N-M << endl;
        return 0;
    }
    
    float target = M;
    while (target > N) target /= 2;
    
    int ans = 0;
    while (N != M) {
        if (ceil(target) < N) {
            N--;
        } else {
            target *= 2;
            N *= 2;
        } ans++;
    }

    cout << ans << endl;
}
