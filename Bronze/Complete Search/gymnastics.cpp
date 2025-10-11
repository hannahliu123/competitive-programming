// LEVEL: Normal (BUT IT TOOK ME FOREVER)
// December 2019 Problem 1

// I understood the question wrong so I was super stuck but then I realized what I
// did wrong, so I started from scratch, but luckily I saved the old one because I
// was able to reuse a big chunk of my code (the really messy loops section)

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int K, N;
    cin >> K >> N;

    vector<vector<int>> ranks;

    for (int i{0}; i < K; ++i) 
    {
        vector<int> temp(N);
        vector<int> edit(N);
        for (int j{0}; j < N; ++j)
        {
            cin >> temp[j];
            edit[temp[j]-1] = j;
        }
        ranks.push_back(edit);
    }

    int ans{0};
    
    for (int col{0}; col < N-1; ++col)
    {
        for (int colComp{col+1}; colComp < N; ++colComp)
        {
            int consistent{0};
            if (ranks[0][col] > ranks[0][colComp])
            {
                for (int row{1}; row < K; ++row)
                {
                    if (ranks[row][col] > ranks[row][colComp]) ++consistent;
                }
            } else if (ranks[0][col] < ranks[0][colComp])
            {
                for (int row{1}; row < K; ++row)
                {
                    if (ranks[row][col] < ranks[row][colComp]) ++consistent;
                }
            }
            
            if (consistent == K-1) ++ans;
        }
    }

    cout << ans << endl;
}
