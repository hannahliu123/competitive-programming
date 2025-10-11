#include <bits/stdc++.h>
using namespace std;

// I definitely over-complicated this. Yeah so my solution ended up not passing
// test case 3, so I read the editorial... I feel kinda dumb omg. I should've
// realized that I could've brute forced my way through this problem. The
// bounds are sooo small. I should've saw "<50" and knew this was a O(N^3)
// problem. That means I can check every single posssibility of people in the
// single-person kayaks. I think I got too caught up with the idea of sorting
// and finding clever algorithms that I forgot about the simpler ways of solving
// these problems. This should've been super simple :(

int main()
{
    int N;
    cin >> N;

    vector<int> weights(N*2);
    for (int i{0}; i < N*2; ++i) {cin >> weights[i];}

    sort(weights.begin(), weights.end());

    int ans{1000000000};
    for (int i{0}; i < N*2-1; ++i) {
        for (int j{i+1}; j < N*2; ++j) {
            int total{0};
            for (int k{0}; k < N*2-1; k++) {
                if (k == i || k == j) continue;
                total += weights[k+1]-weights[k];
                k++;
            } ans = min(ans, total);
        }
    }

    cout << ans << endl;
}
