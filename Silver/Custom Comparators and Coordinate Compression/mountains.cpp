// USACO 2019 January Contest, Silver
// Problem 3. Mountain View

// Start: 9:30
// End: 10:39       1 hr 9 mins

// a bit messy but ik whats going so if it works it works :D ill take it
// I had to spend a while troubleshooting that last test case tho heh

// omg i didnt even need to doo coordinate compression ughhhh

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    int N;
    cin >> N;

    vector<pair<int, int>> peak(N);     // start, end
    for (int i{0}; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        peak[i].first = x-y;
        peak[i].second = x+y;
    }

    // coordinate compress
    int j{0};
    sort(peak.begin(), peak.end()); // sort by start value
    for (int i{0}; i < N-1; ++i) {
        if (peak[i].first == peak[i+1].first) {
            peak[i].first = j;
        } else peak[i].first = j++;
    } peak[N-1].first = j;
    sort(peak.begin(), peak.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    }); // sort by end value
    j = 0;
    for (int i{0}; i < N-1; ++i) {
        if (peak[i].second == peak[i+1].second) {
            peak[i].second = j;
        } else peak[i].second = j++;
    } peak[N-1].second = j;
    sort(peak.begin(), peak.end()); // resort by start value

    int mountains{0};
    int max_seen{-1};     // tracks maximum seen end value
    for (int i{0}; i < N; ++i) {
        // if there was a value greater than the current ending value already seen,
        // then the current peak should not be counted
        if (max_seen < peak[i].second && (i == N-1 || peak[i].first != peak[i+1].first)) {     // valid
            mountains++;
            max_seen = peak[i].second;
        }
    }

    cout << mountains << endl;
}

// WA - 11
