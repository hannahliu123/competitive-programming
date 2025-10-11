// AHH WHY WAS THIS SO HARD
// It's okay tho cos i got it (had to look up some syntax tho ofc)

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main()
{
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int N;
    cin >> N;

    vector<tuple<int, string, int>> log;

    for (int i{0}; i < N; ++i) 
    {
        int day;
        string name;
        int num;
        cin >> day >> name >> num;
        log.push_back(make_tuple(day, name, num));
    }

    sort(log.begin(), log.end());

    int count{0};   // answer
    vector<int> production{7, 7, 7};    // milk production so far
    vector<bool> lead {1, 1, 1};
    vector<bool> prevLead(3);
    int highest{0};
    int prevhighest{0};
    for (int i{0}; i < N; ++i)
    {
        highest = 0;
        if (get<1>(log[i]) == "Bessie")
            production[0] += get<2>(log[i]);
        else if (get<1>(log[i]) == "Elsie")
            production[1] += get<2>(log[i]);
        else if (get<1>(log[i]) == "Mildred")
            production[2] += get<2>(log[i]);
        
        for (int j{0}; j < 3; ++j) if (production[j] > highest) highest = production[j];

        for (int j{0}; j < 3; ++j)
        {
            if (production[j] == highest) lead[j] = 1;
            else lead[j] = 0;
        }

        if (lead != prevLead) ++count;

        prevLead = lead;
        prevhighest = highest;
    }

    cout << count << endl;
}
