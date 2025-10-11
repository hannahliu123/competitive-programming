// CSES - Recursion

// I had no idea how to implement this with recursion, so I looked at the 
// solution, and I only half understand it. I recoded it without looking at
// the solution... uh imma do a ton of practice with this

// We test all subsets of apples and their weights. The recursive function 
// ALWAYS returns the minimum, so we are guarenteed to get the minimum 
// difference as the final answer

// Parameters of recurse(): enough information to uniquely define the current
// state and move the current state towards the base case. What changes at each
// step and what values need to be remembered?
//    - index: Always need an index to keep track of which element you are 
//      currently on/which apple weight you must put in a subset
//    - sum1 & sum2: This sum might change at each step (depending on which 
//      "path" the recursion follows). You need this because you need something
//      that changes when you add an apple to a subset. If you wanted, you 
//      could've used two vectors, but that would make things messier and
//      would result in more calculations needed.
// Ex. if we wanted to do this with three subsets, we would need the parameters: 
// index, sum1, sum2, and sum3. Time Complexity: 3^n (instead of 2^n)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;      // type alias

// define  globally
int N;
vector<int> weight;

// recursion!!! yay...
ll recurse(int i, ll sum1, ll sum2) {      // parameters (see above for details)
    if (i == N) return abs(sum1-sum2);   // base case (if index is not in vector)

    // Try both subsets for weight[i] to go into, then pick the minimum weight
    return min(recurse(i+1, sum1+weight[i], sum2), recurse(i+1, sum1, sum2+weight[i]));
    // increase the index by one no matter what
    // for the first one, add the weight to sum1 (first subset) & keep sum2 same
    // for the other one, add the weight to the second subset & keep sum1 same
}

int main() {
    cin >> N;
    weight.resize(N);   // because weight was defined globally
    for (int i{0}; i < N; ++i) {cin >> weight[i];}

    cout << recurse(0, 0, 0) << endl;  // starting values: index & sums of 0
}
