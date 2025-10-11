// CF - 1420A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t{0}; t < T; ++t) {
        int N;
        cin >> N;

        vector<int> a(N);
        for (int i{0}; i < N; ++i) {cin >> a[i];}

        bool works{false};
        for (int i{0}; i < N-1; ++i) {
            if (a[i] <= a[i+1]) {
                cout << "YES" << '\n';
                works = true;
                break;
            }
        } if (!works) {cout << "NO" << '\n';}
    }
}
