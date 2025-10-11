// January 2025 Problem 1

// Start: 7:39
// End: 9:03
// Total Time: 1 hours and 24 minutes (approx. 1:30)

// Note: OMG I'M ACTUALLY SO PROUD OF MYSELF I WORKED SUPER HARD TO PLANN THIS OUT
// AND IT BASICALLY WORKED EXCEPT FOR ONE PART. ONCE I FIGURED THAT PART OUT I WAS
// ABLE TO COMPLETELY FIX MY CODE TO PASS EVERY SINGLE TEST CASE YIPPEEEEEEEEEEE

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("superposition.in", "r", stdin);
    //freopen("superposition.out", "w", stdout);

    int T; // number of test cases
    cin >> T;

    for (int i{0}; i < T; ++i) {
        int N, A, B;    // size, right, down
        cin >> N >> A >> B;
        bool possible{true};
        char superimposed[N][N];   // [row][column]
        int original[N][N]{};   // [row][column]
        vector<pair<int, int>> gray{};
        vector<pair<int, int>> black{};

        for (int j{0}; j < N; ++j) {    // row
            for (int k{0}; k < N; ++k) {    // column
                char color;
                cin >> color;
                superimposed[j][k] = color;
                if (color == 'G') {gray.push_back({j, k});}
                else if (color == 'B') {black.push_back({j, k});}
            }
        }

        for (int j{0}; j < black.size(); ++j) {
            int x{black[j].first - B};
            int y{black[j].second - A};
            if (x<0 || y<0 || superimposed[x][y]=='W') {
                cout << -1 << '\n';
                possible = false;
                break;
            } else {
                original[x][y] = 1;
                original[x+B][y+A] = 1;
            }
        }

        if (possible) {
            for (int j{0}; j < gray.size(); ++j) {
                if (original[gray[j].first][gray[j].second] != 1) {
                    int x{gray[j].first};
                    int y{gray[j].second};
                    if (x-B<0 || y-A<0 || superimposed[x-B][y-A]=='W') {
                        original[x][y] = 1;
                    } else if (A == 0 && B == 0) {
                        original[x][y] = 1;
                    } else {    // THIS ELSE STATEMENT FIZED EVERYTHING
                        superimposed[x][y] = 'W';
                    }
                }
            }

            int ans{0};
            for (int j{0}; j < N; ++j) {    // row
                for (int k{0}; k < N; ++k) {    // column
                    if (original[j][k] == 1) {
                        ++ans;
                    }
                }
            }

            cout << ans << '\n';
        }
    }
}

// only passed 1, 2, and 3
