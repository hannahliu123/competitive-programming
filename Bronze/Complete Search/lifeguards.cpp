// LEVEL: Normal
// January 2018 Problem 2

// HOLY MOLY HOW DID THIS WORK FIRST TRY?? it's really messy though... WHATEVER!

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm> // min & max
using namespace std;

int main()
{
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> start(N);
    vector<int> end(N);

    for (int i{0}; i < N; ++i) {cin >> start[i] >> end[i];}

    int maxTime{0};
    for (int i{0}; i < N; ++i) // i is the one u skip
    {
        int m{0};
        vector<bool> lifeguard(1001);
        for (int j{0}; j < N; ++j)
        {
            if (j != i)
            {
                for (int k{start[j]}; k < end[j]; ++k)
                {
                    lifeguard[k] = true;
                }
            }         
        }
        for (auto x : lifeguard)
        {
            if (x == true) // dont need the "== true", coudl've just said if(x)
                ++m;
        }
        maxTime = max(maxTime, m);
    }

    cout << maxTime;

}
