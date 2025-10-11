// CP - A - Boredom

// Start: 11:32
// Break: 11:51 - 12:26
// End: 12:51               44 minutes

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> score(100001, 0);  // index 1 represents number 1
    for (int i{0}; i < N; ++i) {
        long long a{};
        cin >> a;
        score[a] += a;
    }

    vector<long long> mx(100001, 0);
    mx[1] = score[1];
    for (int i{2}; i <= 100000; ++i) {
        mx[i] = max(mx[i-1], mx[i-2]+score[i]);
    }

    cout << mx[100000] << endl;
}
