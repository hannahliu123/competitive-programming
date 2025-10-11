// CF - B. World Cup - R1300

// Start: 9:25
// End: 10:11       46 mins (took a long break cos of the... children)

// Gosh this code was really really messy and I didn't even end up using binary search...

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> entrances(N);
    for (int i{0}; i < N; ++i) {
        int people;
        cin >> people;

        int loops = (max(0, people-i)/N);
        if (max(0, people-i)%N != 0) loops++;
        int time = i + loops*N;

        entrances[i] = time;
    }

    pair<int, int> mn_ans{entrances[0], 0};
    for (int i{1}; i < N; ++i) {
        if (entrances[i] < mn_ans.first) {
            mn_ans = {entrances[i], i};
        }
    }

    cout << mn_ans.second+1 << endl;
}
