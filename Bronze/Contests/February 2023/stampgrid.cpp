// Problem 2 (I gave up)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("stampgrid.in", "r", stdin);
    freopen("stampgrid.out", "w", stdout);

    int T; // test cases
    cin >> T;

    for (int tests{0}; tests < T; ++tests) {
        int N{0};
        int K{0};
        cin >> N;
        char desired_painting[N][N];
        char recreation[N][N];
        for (int i{0}; i < N; ++i) {
            for (int j{0}; j < N; ++j) {
                cin >> desired_painting[i][j];
                recreation[i][j] = '.';
            }
        }

        cin >> K;
        char stamp[K][K];
        char stamp2[K][K];
        char stamp3[K][K];
        char stamp4[K][K];
        for (int i{0}; i < K; ++i) {
            for (int j{0}; j < K; ++j) {
                cin >> stamp[i][j];
            }
        }

        for (int i{0}; i < K; ++i) {
            for (int j{0}; j < K; ++j) {
                stamp2[i][j] = stamp[j][K-i+1];
            }
        }

        for (int i{0}; i < K; ++i) {
            for (int j{0}; j < K; ++j) {
                stamp3[i][j] = stamp2[j][K-i+1];
            }
        }

        for (int i{0}; i < K; ++i) {
            for (int j{0}; j < K; ++j) {
                stamp4[i][j] = stamp3[j][K-i+1];
            }
        }

        for (int i{1}; i <= N-K+1; ++i) {
            for (int j{1}; j <= N-K+1; ++j) {
                // I give up maybe ill come back to this problem in the future
            }
        }

        cout << (recreation == desired_painting? "YES" : "NO") << '\n';
    }
}
