// Problem 1 Version 2 except I started rushing cos I ran out of time and this 
// doesn't work like at all

// UPDATE: I came back with a fresh mind after watching like half of the solution
// and it was a lot simpler than I thought. I need to think harder and less 
// narrow-minded-y when I approach simpler Bronze problems (like this)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("hungrycow.in", "r", stdin);
    //freopen("hungrycow.out", "w", stdout);

    int N;          // deliveries
    long long T;    // days
    cin >> N >> T;

    vector<pair<long long, long long>> deliveries(N);
    for (int i{0}; i < N; ++i) {
        cin >> deliveries[i].first >> deliveries[i].second;
    }

    long long available{0};
    long long add{0};
    long long ans{0};
    for (int i{0}; i < N; ++i) {
        available += deliveries[i].second;
        add = min(available, T-deliveries[i].first+1);
        if (i != N-1) add = min(add, deliveries[i+1].first-deliveries[i].first);
        ans += add;
        available -= add;
    }

    cout << ans << endl;
}

// 4, 5, 6, 7, 8, 10, 12
