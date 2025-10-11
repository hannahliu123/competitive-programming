// CF - C. Yet Another Tournament - R1700

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, M;
        cin >> N >> M;          // M time to prepare

        vector<pair<int, int>> opponents(N);   // prep, index
        for (int i{0}; i < N; ++i) {
            cin >> opponents[i].first;
            opponents[i].second = i;
        }

        sort(opponents.begin(), opponents.end());   // sort least -> greatest by prep

        int my_wins{0};         // how many wins you have
        vector<pair<int, int>> beat{};      // stores info on opponents I beat
        for (int i{0}; i < N; ++i) {        // beat as many opponents as possible
            if (M - opponents[i].first >= 0) {
                M -= opponents[i].first;
                my_wins++;
                beat.push_back(opponents[i]);
            }
        }

        // based on our total possible wins, we can definitely place #N-wins+1.
        // HOWEVER, if we can beat the person at the index of wins, then we can 
        // tie in number of wins with them and jump up a place! So, let's see if
        // we either already beat or can replace one of my other wins with them!
        int place{N - my_wins + 1};
        bool worked{false};
        for (int i{0}; i < beat.size(); ++i) {      // try if i already beat them
            if (place != 1 && beat[i].second == my_wins) {
                place--;
                worked = true;
                break;
            }
        }

        // try if I can replace one of my wins with them
        if (place != 1 && !worked && beat.size() > 0) {
            sort(opponents.begin(), opponents.end(), [](auto& a, auto& b){
                return a.second < b.second;
            });   // sort least -> greatest by index
            auto op = opponents[my_wins];

            sort(beat.rbegin(), beat.rend());     // sort opponents I beat by prep
            if (op.first <= beat[0].first+M) place--;
        }

        cout << place << endl;
    }
}
