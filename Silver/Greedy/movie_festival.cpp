// CSES - Movie Festival - https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> movies(N);
    for (auto& p : movies) cin >> p.second >> p.first;      // end, start

    sort(movies.begin(), movies.end());
    
    int ans{1};
    int end{movies[0].first};
    for (int i{1}; i < N; ++i) {
        if (movies[i].second >= end) {
            ans++;
            end = movies[i].first;
        }
    }

    cout << ans << endl;
}
