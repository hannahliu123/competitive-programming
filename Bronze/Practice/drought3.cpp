// Upsolve :D

// Ouhhhhh I like this muahhaahhahhah muy muy muuuuuuy bien
// I think i honestly could've gotten this solution relatively easily if i approached
// this as a greedy problem. Hey w=that jsut means i have more greedy practice to do

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> h(N);
        for (int& i : h) cin >> i;

        int sub{};
        long long ans{0};
        for (int i{0}; i < N-1; ++i) {
            if (h[i] < h[i+1]) {
                if (i == N-2) {
                    ans = -1;
                    break;
                } else {
                    sub = h[i+1] - h[i];
                    h[i+1] -= sub;
                    h[i+2] -= sub;
                    ans += 2*sub;
                    if (h[i+1]<0 || h[i+2]<0) {
                        ans = -1;
                        break;
                    }
                }
            } else if (h[i] > h[i+1]) {
                if (i%2==0) {
                    ans = -1;
                    break;
                } else {
                    for (int j{0}; j<i; j+=2) {
                        sub = h[j]-h[i+1];
                        h[j] -= sub;
                        h[j+1] -= sub;
                        ans += 2*sub;
                        if (h[j]<0 || h[j+1]<0) {
                            ans = -1;
                            break;
                        }
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}
