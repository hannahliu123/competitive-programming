// AtCoder Beginner Contest 214 - E - Packing Under Range Regulations

#include <bits/stdc++.h>
using namespace std;

// WA on a TON of test cases. Why?
// In this solution, I sort the balls based on their ending values. However, simply
// checking each of the balls after sorting is NOT a valid solution. This is because
// I immediately skip over a ton of values competely based on the R value (disregarding
// the L value). 

// This test case is an example of my code failing:
// 1
// 5
// 1 2          #1
// 2 3          #2
// 6 6          #3
// 1 7          #4
// 7 7          #5    

// The correct answer should be "yes" with this order: #1, #2, #4, #3, #5
// However, after the code processes #3, 'box' becomes 7, then #4 uses the value of 7
// even though it could've used 3, 4, or 5. This leave #5 no room when it should've.

// To fix this issue, we simulate this like real life by sorting each ball by it's L
// (first) value. Then, we keep track of all the R (second/ending) values and always choose
// to use (dispose of) the ball with the soonest ending value. See packing_regulations2.cpp

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<pair<int, int>> balls(N);
        for (auto& b : balls) cin >> b.first >> b.second;

        // sort balls by increasing R (second) value
        sort(balls.begin(), balls.end(), [](auto& a, auto& b) {
            if (a.second != b.second) return a.second < b.second;
            else return a.first < b.first;
        });

        bool possible{true};
        int box{balls[0].first + 1};    // index of next unused box
        // Loop through each ball and assign it to the earliest possible box.
        for (int i{1}; i < N; ++i) {
            if (box > balls[i].second) {    // impossible
                possible = false;
                break;
            } else if (box < balls[i].first) {
                box = balls[i].first;       // set box value to earliest L value
            } box++;    // set the box to the NEXT available box (current box is used)
        }

        if (possible) cout << "Yes\n";
        else cout << "No\n";
    }
}
