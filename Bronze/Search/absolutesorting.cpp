// CF - 1772D
// yeah no this doesn't work so I'll come back to it after i learn greedy

#include <bits/stdc++.h>
using namespace std;

int N;

bool check(int num, vector<int>& a) {
    for (int i(0); i < N-1; ++i) {
        if (abs(a[i]-num) > abs(a[i+1]-num)) return false;
    } return true;
}

int main()
{
    int t;
    cin >> t;

    for (int T{0}; T < t; ++T) {
        cin >> N;

        vector<int> a(N);
        for (int i{0}; i < N; ++i) {cin >> a[i];}

        int ans(-1);
        for (int i{1000000000}; i >= 1; i /= 2) {
            while (check(ans+i, a)) {ans += i;}
        }

        cout << ans << '\n';
    }
}
