// Priority Queues Practice
// CSES - Room Allocation - https://cses.fi/problemset/task/1164

// Start: 10:09
// End: 10:52           43 mins

// This was messy and took a while because I didn't realize the input could be
// out of order. Ig this wasn't something I could've avoided even if I drew out 
// more test cases to test my solution, but either way, I probably should've planned
// this out better. It would've saved some time but wtv

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<pair<int, int>, int>> customers(N);
    for (int i{0}; i < N; ++i) {
        cin >> customers[i].first.first >> customers[i].first.second;
        customers[i].second = i;
    }
    sort(customers.begin(), customers.end());

    priority_queue<pair<int, int>> departure{};    // negative values for min-heap
    int max_rooms{0};
    vector<int> rooms(N);
    for (int i{0}; i < N; ++i) {
        int a = customers[i].first.first, d = customers[i].first.second;

        if (i > 0 && departure.top().first*-1 < a) {
            departure.push({-1*d, departure.top().second});
            rooms[customers[i].second] = departure.top().second;
            departure.pop();
        } else {
            departure.push({-1*d, departure.size()+1});     // new room
            rooms[customers[i].second] = departure.size();
        }
        
        max_rooms = max(max_rooms, (int)departure.size());
    }

    cout << max_rooms << '\n';
    for (auto& r : rooms) cout << r << ' ';
}
