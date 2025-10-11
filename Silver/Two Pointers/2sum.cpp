// CSES - Sum of Two Values - https://cses.fi/problemset/task/1640

// Start: 9:37
// End: 9:52        15 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<pair<int, int>> a(N);
    for (int i{1}; i <= N; ++i) {
        int x;
        cin >> x;
        a[i-1] = {x, i};
    }

    sort(a.begin(), a.end());

    int left{0}, right{N-1};
    while (left < right) {
        int sum = a[left].first + a[right].first;
        if (sum == X) break;
        else {
            if (sum > X) right--;
            else left++;
        }
    }

    if (a[left].first + a[right].first == X && left != right) {
        cout << a[right].second << ' ' << a[left].second << endl;
    } else cout << "IMPOSSIBLE" << endl;
}
