#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));
    vector<vector<int>> B(N, vector<int>(M));

    for (int i{0}; i < N; ++i) {
        for (int j{0}; j < M; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i{0}; i < N; ++i) {
        for (int j{0}; j < M; ++j) {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> ans(N, vector<int>(M));
    for (int i{0}; i < N; ++i) {
        for (int j{0}; j < M; ++j) {
            ans[i][j] = A[i][j] + B[i][j];
        }
    }
    
    for (int i{0}; i < N; ++i) {
        for (int j{0}; j < M; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << endl;
}
