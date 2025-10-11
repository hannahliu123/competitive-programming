// Level: Easy
// December 2019 Problem 2

// AHAHHAH THIS TOOK KINDA LONG BUT I COOKED AND FIGURED IT OUT EVEN THOUGH MY
// MY CODE IS NOT READABLE AT ALL. OMG IM SO SURPRISED IT DOESN'T SURPASS ANY
// TIME OR MEMORY LIMITS COS HOLY HEDGEHOG DO I USE A TON OF LOOPITY DOOPITIES

// Oh wait this was suppoused to be easy erm my bad

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    
    int N;
    cin >> N;

    string colors;
    cin >> colors;

    for(int i{1}; i < N; ++i) {     // i - how many letters long
        set<string> temp;
        bool works{true};
        for (int j{0}; j < N; ++j) {      // j - starting index
            string compare;
            for (int k{j}; k < i+j; ++k) {
                compare.push_back(colors[k]);
            }

            if (temp.count(compare)) {
                works = false;
                break;
            } else temp.insert(compare);
        }

        if (works) {
            cout << i << endl;
            break;
        }
    }

}
