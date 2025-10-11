// LEVEL: Normal
// US Open 2017 Problem 2

// NO FRICKING WAY FIRST TRY AHHAHHHAHA IM GOATED TODAY LET ME COOOOOOOOOOK

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<vector<char>> spotty;
    vector<vector<char>> plain;

    for (int i{0}; i < 2*N; ++i)
    {
        vector<char> cow(M);
        for (int j{0}; j < M; ++j)
        {
            cin >> cow[j];
        }
        if (i < N)
            spotty.push_back(cow);
        else
            plain.push_back(cow);
    }

    int ans{0};
    for (int i{0}; i < M; ++i) // column
    {
        bool potential{true};
        vector<char> spottyCows;
        for (int j{0}; j < N; ++j) // row
        {
            spottyCows.push_back(spotty[j][i]);
        }

        for (auto cow : spottyCows)
        {
            for (int j{0}; j < N; ++j)
            {
                if (plain[j][i] == cow)
                {
                    potential = false;
                    break;
                }
            }
        }
        if (potential) ++ans;
    }

    cout << ans;
}
