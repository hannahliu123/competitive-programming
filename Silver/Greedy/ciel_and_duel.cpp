// CF - B. Ciel and Duel - R1900

// Start: 3:07
// Break: 4:26 - 7:26
// End: 7:50                WA - 15         1hr 43mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> atk{};      // Jiro's ATK cards
    vector<int> def{};      // Jiro's DEF cards
    for (int i{0}; i < N; ++i) {    // Jiro's Cards
        string pos;
        int strength;
        cin >> pos >> strength;
        if (pos == "ATK") atk.push_back(strength);
        else def.push_back(strength);
    }

    vector<int> ciel(M);    // Ciel's cards (all attack)
    for (auto& c : ciel) cin >> c;

    // Try killing some amount of ATK cards to maximize damage
    sort(atk.begin(), atk.end());       // least -> greatest
    sort(ciel.rbegin(), ciel.rend());   // greatest -> least

    int max_damage{0};
    bool possible = true;
    for (int i{1}; i <= atk.size(); ++i) {  // kill i ATK cards
        int k = i-1;        // index of ciel's cards
        if (k > M-1) {      // not enough ciel cards
            possible = false;
            break;
        }

        int damage = 0;
        for (int j{0}; j < i; ++j) {        // up to index j of ATK cards
            if (ciel[k] >= atk[j]) {        // possible
                damage += ciel[k] - atk[j];
            } else {
                possible = false;
                break;
            }
            k--;
        }

        if (!possible) break;
        max_damage = max(max_damage, damage);
    }

    // all ATK cards were defeated; use remaining cards
    if (possible && def.size() == 0 && M > N) {
        int c = accumulate(ciel.begin(), ciel.end(), 0);
        int j = accumulate(atk.begin(), atk.end(), 0);
        max_damage = max(max_damage, c - j);
    }

    // try killing all DEF cards
    possible = true;
    if (def.size() > 0 && M > N) {
        sort(def.rbegin(), def.rend());         // greatest -> least
        sort(ciel.begin(), ciel.end());         // least -> greatest
        for (int i{0}; i < def.size(); ++i) {
            // see if possible to defeat that card with lowest possible card
            int index = upper_bound(ciel.begin(), ciel.end(), def[i]) - ciel.begin();
            if (index >= ciel.size() || index < 0) {
                possible = false;
                break;
            } else {
                ciel.erase(ciel.begin() + index);
            }
        }

        // now check if it's possible to kill all the ATK cards & use up remaining
        if (possible) {
            sort(atk.rbegin(), atk.rend());     // greatest -> least
            sort(ciel.rbegin(), ciel.rend());   // greatest -> least
            for (int i{0}; i < atk.size(); ++i) {
                if (ciel[i] < atk[i]) {     // not possible
                    possible = false;
                    break;
                }
            }

            if (possible) {
                int c = accumulate(ciel.begin(), ciel.end(), 0);
                int j = accumulate(atk.begin(), atk.end(), 0);
                max_damage = max(max_damage, c - j);
            }
        }
    }

    cout << max_damage << endl;
}
