#include <bits/stdc++.h>
using namespace std;

// After reading the solution: sum is at least the previous variable (unless 
// there was a chain of previous variables that was larger than just the 
// previous num itself). Best contains the best sum, so once the highest value 
// is calculated, it won't go back down.

// This solution works in O(N) time. I could've easily gotten an O(N^3) solution 
// and probably an O(N^2) solution on my own by using a counter variable. To get
// this solution, would have to first decide what I would use my one loop to
// track. I would know to loop through each number in nums, and I think I would
// figure out to use it as the last (rightmost) number. From there, I would
// decide how to calculate the max up until that number without any loops. Then
// I would need to break down the problem and realize I can take the maximum of
// either the number itself or the sum of itself and some numbers before it. OK
// I GOT IT! So if I drew out how it would work on a peice of paper for each 
// iteration of the loop, it would look like:
//
// -1  2  2+4=6  6-3=3  3+5=8  8+2=10  10-5=5  5+2=7
// -1  2    4     -3      5      2       -5      2
//
// From there, I would notice that the answer (10) is just the maximum of those
// sums. I would also notice that to calculate the sum, all you take is either
// the number itself (first two) or the sum of iself and the greatest sum before
// it! Then I would get to the solution.

// Lesson: If you know the maximum number of loops you can use (N<5000 O(N^2),
// N<500 O(N^3), N<10^6 O(N)), then you can figure out what you want to loop
// over. From there, you can draw out test cases and look for patterns.

int main()
{
    vector<int> nums{-1, 2, 4, -3, 5, 2, -5, 2};

    int sum{0};
    int best{0};
    for (int i{0}; i < nums.size(); ++i) {
        sum = max(nums[i], sum+nums[i]);
        best = max(best, sum);
    }

    cout << best << endl;
}
