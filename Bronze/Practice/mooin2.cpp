// January 2025 Problem 2

// Start: 8:27
// End: 9:48 

// I gave up on the last few test cases. Ughhh idk how to match the time complexity

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("mooin.in", "r", stdin);
    //freopen("mooin.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> nums(N);
    set<int> lastTwo{};

    set<int> appearOnce{};
    set<int> appearTwice{};
    for (int i{0}; i < N; ++i) {
        cin >> nums[i];
        if (appearOnce.count(nums[i])) {appearTwice.insert(nums[i]);}
        else if (i!=0) appearOnce.insert(nums[i]);
    }

    long long ans{0};
    set<int> track{};
    for (int i{N-1}; i > 1; --i) {    // starts from end
        if (lastTwo.count(nums[i]) && !track.count(nums[i]) && appearTwice.count(nums[i])) { // if have seen the number before and we know it appears twice
            set<int> diffNum{};
            for (int j{i}; j >= 0; --j) {
                diffNum.insert(nums[j]);    // includes one extra
            }
            ans += diffNum.size()-1;
            track.insert(nums[i]);
            //if (lastTwo == appearTwice) break;
        } else lastTwo.insert(nums[i]);
    }
    cout << ans << endl;
}

// 8, 9, 10, 11 timeout
// 1088 1073 1070
// 1076 1067 1066
// 1115 1106 1105
