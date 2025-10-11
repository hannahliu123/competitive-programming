// CSES - Restaurant Customers - https://cses.fi/problemset/task/1619

// Start: 8:32
// End: 8:45        13 mins!!!

//LES GOOOO I HAVENT FIRST-TRIED A PROBELM IS SO LONG THIS FEELS AMAZING

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, char>> times{};

int compress(pair<int, char> x) {
    return lower_bound(times.begin(), times.end(), x) - times.begin();
}

int main() {
    int N; 
    cin >> N;
    
    for (int i{0}; i < N; ++i) {
        int a, l;
        cin >> a >> l;
        times.push_back({a, 'a'});
        times.push_back({l, 'l'});
    }

    // sort & remove duplicates
    sort(times.begin(), times.end());
    times.erase(unique(times.begin(), times.end()), times.end());

    // create compressed diff array
    vector<int> diff(times.size());
    for (int i{0}; i < times.size(); ++i) {
        if (times[i].second == 'a') {
            diff[compress(times[i])] += 1;
        } else {
            diff[compress(times[i])] -= 1;
        }
    }

    // Build final array
    for (int i{1}; i < times.size(); ++i) {
        diff[i] += diff[i-1];
    }

    int ans = *max_element(diff.begin(), diff.end());
    cout << ans << endl;
}
