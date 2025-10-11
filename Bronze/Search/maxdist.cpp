#include <bits/stdc++.h>
using namespace std;

// Very easy (just brute forced it)

int main()
{
    int N;
    cin >> N;

    vector<int> x(N);
    vector<int> y(N);
    for (int i{0}; i < N; ++i) {cin >> x[i];}
    for (int i{0}; i < N; ++i) {cin >> y[i];}

    int ans{0};
    for (int i{0}; i < N-1; ++i) {
        for (int j{i+1}; j < N; ++j) {
            ans = max(ans, (x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i]));
        }
    }

    cout << ans << endl;
}
