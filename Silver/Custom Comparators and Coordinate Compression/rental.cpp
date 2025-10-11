// USACO 2018 January Contest, Silver
// Problem 2. Rental Service

// Start: 9:04
// End: 10:30       1hr 26 mins

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    int N, M, R;
    cin >> N >> M >> R;

    vector<ll> cows(N);                    // c gallons of milk/day
    vector<pair<ll, ll>> store(M);        // p cents/gal, buy max q gals
    vector<ll> rent(R);                    // rent a cow for r cents/day
    for (auto& c : cows) cin >> c;
    for (auto& p : store) cin >> p.second >> p.first;
    for (auto& r : rent) cin >> r;

    // Sort everything (greatest -> least)
    sort(cows.rbegin(), cows.rend());
    sort(store.rbegin(), store.rend());
    sort(rent.rbegin(), rent.rend());

    // Generate prefix sums (still 0-indexed)
    for (int i{1}; i < N; ++i) cows[i] += cows[i-1];
    for (int i{1}; i < R; ++i) rent[i] += rent[i-1];
    store[0].first *= store[0].second;
    for (int i{1}; i < M; ++i) {
        store[i].first *= store[i].second;
        store[i].first += store[i-1].first;
        store[i].second += store[i-1].second;
    }
    
    // Try to sell/rent out j cows
    ll total_profit{0};
    for (int j{0}; j <= min(R, N); ++j) {
        ll rent_profit = j==0? 0LL: rent[j-1];
        ll milk_gallons = j==N? 0LL : cows[N-j-1];  // N-mid cows to milk

        // binary search for milk profit (i = index with value greater that or equal to)
        int i = lower_bound(store.begin(), store.end(), make_pair(0LL, milk_gallons), [](auto& a, auto& b) {
            return a.second < b.second;
        }) - store.begin();
        
        ll milk_profit = 0;
        if (i >= M) {            // too many gallons of milk
            i = M-1;
            milk_profit = store[i].first;
        } else if (store[i].second > milk_gallons) {        // in between values
            if (i == 0) {
                milk_profit = (store[i].first/store[i].second) * milk_gallons;
            } else {
                milk_profit = store[i-1].first;
                milk_profit += (milk_gallons - store[i-1].second)*(store[i].first - store[i-1].first)/(store[i].second - store[i-1].second);
            }
        } else if (store[i].second == milk_gallons) milk_profit = store[i].first;   // fits perfectly

        ll profit = rent_profit + milk_profit;
        total_profit = max(total_profit, profit);
    }

    cout << total_profit << endl;
}
