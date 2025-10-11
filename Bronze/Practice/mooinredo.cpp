// My attempt at It's Mooin' Time II 1 day after reading the solution :')

// Wait so I forgot how the solution code worked, so I made this and it actually
// worked wth. I did not think this code would work but im not complaining!

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("mooin.in", "r", stdin);
    //freopen("mooin.out", "w", stdout);

    int N;
    cin >> N;

    vector<vector<int>> positions(N);
    vector<int> nums(N);
    for (int i{0}; i < N; ++i) {
        cin >> nums[i];
        positions[nums[i]-1].push_back(i);
    }

    set<int> secondLast{};
    for (auto position : positions) {
        if (position.size() >= 2) {
            secondLast.insert(position[position.size()-2]);
        }
    }

    long long ans{0};
    set<int> uniqueNums{};
    for (int i{0}; i < N; ++i) {
        uniqueNums.insert(nums[i]);
        if (secondLast.count(i)) {
            ans += uniqueNums.size()-1;
        }
    }

    cout << ans << '\n';
}
