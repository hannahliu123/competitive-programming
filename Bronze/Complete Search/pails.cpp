// LEVEL: Easy
// February 2016 Problem 1

// Yeah okay this was way too easy hehe

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int X, Y, M;
    cin >> X >> Y >> M;
    
    int ans{0};
    for (int i{0}; i*X <= M; ++i)
    {
        for (int j{0}; i*X + j*Y <= M; ++j)
        {
            ans = max(ans, i*X + j*Y);
        }
    }

    cout << ans << endl;
}
