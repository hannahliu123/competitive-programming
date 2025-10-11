// Problem 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("hungrycow.in", "r", stdin);
    //freopen("hungrycow.out", "w", stdout);

    int N;          // deliveries
    long long T;    // days
    cin >> N >> T;

    map<long long, long long> deliveries{};
    for (int i{0}; i < N; ++i) {
        long long d, b;
        cin >> d >> b;
        deliveries[d] = b;
    }

    long long available{0};
    long long ans{0};
    for (int i{0}; i < T; ++i) {
        if (deliveries.count(i+1)) {      // is there something to check if it exists?
            available += deliveries[i+1];
        } if (available > 0) {
            ans++;
            available--;
        }
    }

    cout << ans << endl;
}

// 8, 9, 10, 11, 12, 13 timeout
