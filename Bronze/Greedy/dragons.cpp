// CF - 230A, R1000

// This solution was very easy and straightforward :)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s, n;
    cin >> s >> n;

    vector<pair<int, int>> dragon_s_bonus(n);
    for (int i{0}; i < n; ++i) {
        cin >> dragon_s_bonus[i].first >> dragon_s_bonus[i].second;
    }

    sort(dragon_s_bonus.begin(), dragon_s_bonus.end());

    for (int i{0}; i < n; ++i) {
        if (dragon_s_bonus[i].first >= s) {
            cout << "NO" << endl;
            return 0;
        } s += dragon_s_bonus[i].second;
    } cout << "YES" << endl;
}
