// USACO 2021 February Contest, Silver
// Problem 3. Just Green Enough

// I had to see the "prefix sums" label before i realized how to approach this problem.
// I was kinda just staring at it for over an hour drawing out test cases and trying to 
// find patterns but nothing was working. I ended up looking at the label and that makes
// so much more sense. I haven't looked at the solution yet, but i think we need to
// create a 2d prefix sum array tracking the number of 100s in that subrectangle which 
// will take O(N^2) time. I think we might need another 2d prefix array for tracking the
// number of squares below 100 (cannot be included). 

// okay this was really confusiung bc I had absolutely no idea how to solve this within
// the time complexity. during the real contest i think ill just resort to solving for a
// few test cases. basically for this problem, instead of directly calculating the 
// subgrids with the minimum square being 100, you want to calculate the subgrids with
// all values >= 100 then subtract the number of subgrids with all values >100. then you
// will be left with the subgrids with all values >= 100 and also with at least one value
// equal to 100 (bc the ones without this would've been subtracted). This is the desireable
// approach because directly finding the subgrids with at least one 100 complicates a lot
// of stuff. this is bc if you only focus on all values being greater than a certain value,
// you can quickly decide whether or not to include a value (yes, as long as it is greater
// than that value). This is an easy decision. But for the other way, you need to keep a 
// count of whether your subset contains an 100 which is very fragile. btw we utilize
// complementary counting here to get to the final solution by breaking it up into seperate
// parts. typically you want to do this for any problem that asks for exactly something

// next to actually calculate the number of subsets (where valid squares are greater than
// a certain value), you need to use 1d compression where i just spent way too long yapping
// about and trying to understand in google docs. i think i get it now and i feel rly happy
// abt that but idek if im every gonna use it again. oh well always good to know. imma try
// to implement it now :D

#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<bool>> use;

long long subsets() {   // subsets of ones (valid) in use
    long long ans = 0;
    for (int i{0}; i < N; ++i) {
        // true if that index is true in use through all rows i -> j
        vector<bool> strip = use[i];
        for (int j{i}; j < N; ++j) {
            // height is j-i+1
            int run = 0;
            for (int k{0}; k < N; ++k) {
                // check if index k in row j is true
                strip[k] = strip[k] & use[j][k];
                if (strip[k]) ans += ++run;
                else run = 0;
            }
        }
    }
    return ans;
}

int main() {
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i{0}; i < N; ++i) {
        for (int j{0}; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    // calculate number of subsets of values >= 100
    use.resize(N, vector<bool>(N));
    for (int i{0}; i < N; ++i) {
        for (int j{0}; j < N; ++j) {
            use[i][j] = grid[i][j]>=100;
            // true if the value at that index >= 100, false otherwise
        }
    }
    long long ans = subsets();
    
    // subtract number of subsets of values purely > 100
    for (int i{0}; i < N; ++i) {
        for (int j{0}; j < N; ++j) {
            use[i][j] = grid[i][j]>100;
        }
    }
    ans -= subsets();

    cout << ans << endl;
}
