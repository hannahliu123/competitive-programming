// D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;      // num groups & classrooms

        vector<pair<int, int>> classrooms(M);   // floor, room number
        for (int i{0}; i < M; ++i) {
            cin >> classrooms[i].second;
            classrooms[i].first = classrooms[i].second/100;
        }

        sort(classrooms.begin(), classrooms.end());
        
        int lo{0}, hi{M-1};
        bool used_twice{false};
        for (int i{0}; i < N; ++i) {
            for (int i{1}; i <= 3; ++i) cout << classrooms[lo].second << ' ' << classrooms[hi].second << ' ';
            if (!used_twice) {
                swap(lo, hi);
                used_twice = true;
            } else {  // used twice
                swap(lo, hi);
                lo++;
                hi--;
                used_twice = false;
            } cout << '\n';
        }
    }
}
