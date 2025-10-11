// Problem 2

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long length = 0;
    bool possible = true;
    vector<char> s{};
    vector<pair<char,long long>> pairs{};
    for (int i{0}; i < N; ++i) {
        char c;
        long long l;
        cin >> c >> l;
        pairs.push_back({c, l});
    }

    for (int i{0}; i < N; ++i) {
        length += pairs[i].second;
        if (length > 100) {
            possible = false;
            break;
        } else {
            for (int j{0}; j < pairs[i].second; ++j) s.push_back(pairs[i].first);
        }
    }

    if (possible) {
        for (auto i : s) cout << i;
        cout << endl;
    } else {
        cout << "Too Long" << endl;
    }
}
