// YESSIR IT FINALLY WORKED (but its super duper messy and i cant even read it)

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    
    int seg, bSeg;
    cin >> seg >> bSeg;

    vector<int> lenSpeed(2*seg); // didn't need a vector for this (could've just used temporary variables in the for loop)
    vector<int> limit(100);

    int k{0};
    for (int i{0}; i < 2*seg; i += 2) 
    {
        cin >> lenSpeed[i] >> lenSpeed[i+1]; // could've used temporary variables instead of assigning a vector index

        for (int j{0}; j < lenSpeed[i]; ++j)
        {
            limit[k] = lenSpeed[i+1];
            ++k;
        }
    }
    
    vector<int> bLenSpeed(2 * bSeg); // same here :(
    vector<int> bessie(100);

    int l{0};
    for (int i{0}; i < 2*bSeg; i += 2) 
    {
        cin >> bLenSpeed[i] >> bLenSpeed[i+1];

        for (int j{0}; j < bLenSpeed[i]; ++j)
        {
            bessie[l] = bLenSpeed[i+1];
            ++l;
        }
    }

    int max{0};
    for (int i{0}; i < 100; ++i)
    {
        if (bessie[i] - limit[i] > max)
            max = bessie[i] - limit[i];
    }

    cout << max;

    return 0;
}
