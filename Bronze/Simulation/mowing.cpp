// I had to check the solution to figure out we should use a vector of pairs (coordinates)
// AHH BUT I COOKED EHEHHEHE

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int N;
    cin >> N;

    char D;
    int S;
    vector<pair<int, int>> lawn{make_pair(0,0)}; // index of lawn is t
    int x{1000}; // answer
    for (int i{0}; i < N; i ++) 
    {
        cin >> D >> S;
        for (int j{0}; j < S; ++j)
        {
            int xVal = lawn[lawn.size() - 1].first;
            int yVal = lawn[lawn.size() - 1].second;

            if (D == 'N')       ++yVal;
            else if (D == 'E')  ++xVal;
            else if (D == 'S')  --yVal;
            else if (D == 'W')  --xVal;
            
            for (int j{0}; j < lawn.size(); ++j)
            {
                if (make_pair(xVal, yVal) == lawn[j])
                    x = min(x, static_cast<int>(lawn.size() - j));
            }

            lawn.push_back(make_pair(xVal, yVal));
        }
    }

    cout << (x == 1000? -1 : x) << endl;
}
