// Level: Normal
// January 2017 Problem 1

// 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    int N;
    cin >> N;

    map<string, int> log {
        {"Bessie", 0},
        {"Elsie", 0},
        {"Daisy", 0},
        {"Gertie", 0},
        {"Annabelle", 0},
        {"Maggie", 0},
        {"Henrietta", 0},
    };

    for (int i{0}; i < N; ++i) {
        string name;
        int amount;
        cin >> name >> amount;
        log[name] += amount;
    }

    vector<pair<int, string>> numLog(7);

    int i{0};
    for (auto cow : log) {
        numLog[i].first = cow.second;
        numLog[i].second = cow.first;
        ++i;
    }

    sort(numLog.begin(), numLog.end());

    int notlast{0};
    int last{numLog[0].first};
    for (int i{1}; i < 7; ++i) {
        if (numLog[i].first > last) {
            notlast = numLog[i].first;
            break;
        }
        
        if (i == 6) {
            cout << "Tie" << endl;
            return 0;
        } 
    }

    vector<string> ans;
    for (int i{0}; i < 7; ++i) {
        if (numLog[i].first == notlast) {
            ans.push_back(numLog[i].second);
        };
    }

    if (ans.size() > 1) cout << "Tie" << endl;
    else cout << ans[0] << endl;
}
