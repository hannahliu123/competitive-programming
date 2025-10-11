// CSES - Sum of Three Values - https://cses.fi/problemset/task/1641

// Start: 10:01
// End: 10:06           5 mins!!!

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<pair<int, int>> a(N);
    for (int i{0}; i < N; ++i) {
        int x; 
        cin >> x;
        a[i] = {x, i+1};
    }

    sort(a.begin(), a.end());

    for (int i{0}; i < N-2; ++i) {
        int left{i+1}, right{N-1};
        while (left < right) {
            int sum = a[i].first + a[left].first + a[right].first;
            if (sum == X) {
                cout << a[i].second << ' ' << a[left].second << ' ' << a[right].second << endl;
                return 0;
            } else if (sum > X) right--;
            else left++;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}
