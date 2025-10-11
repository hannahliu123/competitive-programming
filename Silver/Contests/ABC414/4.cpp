// Problem 4

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> house(N);
    for (auto& l : house) cin >> l;

    sort(house.begin(), house.end());

    vector<long long> gaps{};   // only need first M-1
    for (int i{1}; i < N; ++i) {
        gaps.push_back(house[i] - house[i-1]);
    }

    sort(gaps.rbegin(), gaps.rend());   // greatest -> least

    long long ans = house[N-1] - house[0];
    for (int i{0}; i < M-1; ++i) {
        ans -= gaps[i];
    }

    cout << ans << endl;
}
