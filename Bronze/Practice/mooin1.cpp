#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> nums(N);
    set<int> lastTwo{};

    set<int> appearOnce{};
    set<int> appearTwice{};
    for (int i{0}; i < N; ++i) {
        cin >> nums[i];
        if (appearOnce.count(nums[i])) {appearTwice.insert(nums[i]);}
        else appearOnce.insert(nums[i]);
    }

    long long ans{0};
    for (int i{N-1}; i > 1; --i) {    // starts from end
        if (!lastTwo.count(nums[i]) && appearTwice.count(nums[i])) {
            for (int j{i-1}; j > 0; --j) {
                if (nums[i] == nums[j]) {
                    set<int> diffNum{};
                    for (int k{j}; k >= 0; --k) {
                        diffNum.insert(nums[k]);    // includes one extra
                    }
                    ans += diffNum.size()-1;
                    break;
                }
            } lastTwo.insert(nums[i]);
        }
    }
    cout << ans << endl;
}
