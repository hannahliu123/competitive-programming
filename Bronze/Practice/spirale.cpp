// COCI '17 Contest 5 #2 Spirale

// Start: 1:13
// End: 3:21        2 hrs 8 mins

// This took a relaly long time partially because i overcommitted, and also because i
// didn't know how to orgainize this work. It was all really complicated, but at least
// my idea wasn't a flop and i didn't waste my time. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> ans(N);
    for (auto& i : ans) {
        for (int j{0}; j < M; ++j) i.push_back(1000000000);
    }

    for (int l{0}; l < K; ++l) {    // fill entire grid & update if minimum
        int x, y, t;
        cin >> x >> y >> t;
        --x; --y;
        if (t == 0) {
            for (int i{0}; i < N; ++i) {
                for (int j{0}; j < M; ++j) {
                    int num{0}, x1{i-x}, y1{j-y};
                    if (x1 >= 0 && (y1>=-x1 && y1<=x1)) { // find v^, count <->
                        num = 4*(x1*x1)+x1+1-y1;
                    } else if (x1 < 0 && (y1>=x1+1 && y1<=-x1)) {
                        num = 4*(x1*x1)+3*x1+1+y1;
                    } else {
                        if (y1 >= 0) {
                            num = 4*(y1*y1)-y1+1+x1;
                        } else {
                            num = 4*(y1*y1)-3*y1+1-x1;
                        }
                    } ans[i][j] = min(ans[i][j], num);
                }
            }
        } else {
            for (int i{0}; i < N; ++i) {
                for (int j{0}; j < M; ++j) {
                    int num{0}, x1{i-x}, y1{j-y};
                    if (x1 >= 0 && (y1>=-x1 && y1<=x1)) {
                        num = 4*(x1*x1)+x1+1+y1;
                    } else if (x1 < 0 && (y1>=x1 && y1<=-x1-1)) {
                        num = 4*(x1*x1)+3*x1+1-y1;
                    } else {
                        if (y1 >= 0) {
                            num = 4*(y1*y1)+3*y1+1-x1;
                        } else {
                            num = 4*(y1*y1)+y1+1+x1;
                        }
                    } ans[i][j] = min(ans[i][j], num);
                }
            }
        }
    }

    for (auto i : ans) {
        for (int j : i) {
            cout << j << ' ';
        } cout << '\n';
    }
}
