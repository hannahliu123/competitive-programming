// TLE redo (w/o seeing solution) for CF - 1863B, R1100

// AHHH IM GOATED. I'm so happy that this works. This is that faster version
// of split sort. I used a lot of paper and test cases for this problem, so 
// I'm super happy that I was able to solve it!

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i{0}; i < n; ++i) {cin >> p[i];}
        
        vector<int> index(n);
        for (int i{0}; i < n; ++i) {
            index[p[i]-1] = i;
        }

        int chain{0};
        for (int i{1}; i < n; ++i) {
            if (index[i] > index[i-1]) ++chain;
        }

        cout << n-1-chain << '\n';
    }
}
