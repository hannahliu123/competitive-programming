// LEVEL: Normal
// December 2019 Problem 3

// I was so close but I thought I had the wrong idea, so I gave up (this always happens...)

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int N{0};
    cin >> N;
    vector<string> cows{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    vector<string> order1(N);   // next time consider using a vector or pairs (.first & .second)
    vector<string> order2(N);
    string p;

    for (int i{0}; i < N; ++i) {cin >> order1[i] >> p >> p >> p >> p >> order2[i];}
    sort(cows.begin(), cows.end());

    do {
        bool works{true};
        for (int i{0}; i < N; ++i)
        {
            for (int j{0}; j < 8; ++j)
            {
                if (cows[j] == order1[i] && j > 0 && j < 7)
                {
                    if (cows[j+1] != order2[i] && cows[j-1] != order2[i]) works = false;
                }
                else if (cows[j] == order1[i] && j == 0 && cows[j+1] != order2[i]) works = false;
                else if (cows[j] == order1[i] && j == 7 && cows[j-1] != order2[i]) works = false;
            }
        }
        if (works) break;   // use break to exit a loop :)
    } while (next_permutation(cows.begin(), cows.end()));

    for (auto cow : cows)
        cout << cow << '\n';
}
