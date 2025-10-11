// Level: Easy
// Feburary 2019 Problem 1

// OH. MY. GOODYGOODNESS. The stupid equation works 😭 omg how did i figure that
// out. Uhh only problem is that this was suppoused to be easy... heh

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    vector<int> order(3);
    cin >> order[0] >> order[1] >> order[2];

    int minMoves{2};
    int maxMoves{max(order[2]-order[1]-1, order[1]-order[0]-1)};

    if (order[0]+1 == order[1] && order[1]+1 == order[2]) minMoves = 0;
    else if (order[0]+2 == order[1] || order[1]+2 == order[2]) minMoves = 1;

    // while (order[0]+1 != order[1] || order[1]+1 != order[2]) {
    //     if (order[2]-order[1] >= order[1]-order[0]) {   // move order[0]
    //         order[0] = order[1];
    //         order[1] += 1;
    //         ++maxMoves;
    //     } else if (order[2]-order[1] < order[1]-order[0]) {
    //         order[2] = order[1];
    //         order[1] -= 2;
    //         ++maxMoves;
    //     }
    // }

    cout << minMoves << '\n';
    cout << maxMoves << endl;
}

// 3, 4, 5, 6, 8, 9, 10 timeout
// 2, 4, 6, 7 wrong
// 4, 6, 7 wrong
