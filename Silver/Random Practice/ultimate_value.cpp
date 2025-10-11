// CF - C. Ultimate Value - R1500 - 09/22/2025

// I spent 2 hours on this problem and couldn't figure out how to solve it so i looked at the
// editorial. i was sooo close, even though i took me a rly long time to figure some important
// stuff out, but i realized that you only really need to solve for alice's optimal move, and
// bob will end the game bc alice can always reverse his moves for increased cost. so, alice
// only has a few options: end the game, swap even/even or odd/odd for an increased cost, or
// swap even/odd or odd/even for increased cost or higher f(a). This is where i got stuck tho,
// bc i had no idea how to calculate what alice's optimal move would be

// ALRIGHT this problem is one of THOSE problems where it takes me a bajillion years to 
// understand but i think i kinda got it now... So the way to calculate the optimal move
// for alice is to simply loop from left to right and consider two different cases. there
// are a ton of ways to implement this bc ur considered two cases, so you could fit it all
// in one loop or split it up or whatever. but the two cases are either odd or even indexes.
// Im gonna start explaining using 0-based indexing because that's what the code will use,
// so lets break the cases apart:
// 1.   When you reach an even index (0, 2, 4...) that means the value there is being ADDED.
//      For each even index you reach, you want to keep track of/update the most optimal even
//      index that you've seen so far as well as potentially update the answer using the
//      current even index and the previously declared most optimal odd index. Now the question
//      is how you determine these optimal indexes. 
//      To determine optimal indexes, let's consider the first case above. The even index is on
//      the right, so odd is l and even is r. To determine the cost when swapping l and r, you
//      just need to determine the cost & difference when swapping. The cost is simple: r-l.
//      The equation before swapping will be a_r-a_l (because l is odd and negative and r is 
//      even and positive). So, after swapping it'll be a_l-a_r. The difference, or 
//      a_l-a_r - (a_l-a_r) yields 2(a_l - a_r). The total increase will be r-l + 2(a_l - a_r).
//      Becuse you want to MAXIMIZE the total increase (alice wants to maximize it), you want
//      to find a good balance between r & l. It's much easier to visualize this when the
//      variables are isolated. So, rewrite the equation as (r - 2a_r) - (l - 2a_l), and 
//      remember that r is still even and l is odd. This means, whenever you loop through the
//      array and meet an even index, you want to try updating the answer using that index as
//      r and the pre-calculated l index as l. Clearly, in that equation, it is obvious that
//      you want a small value that equals (l - 2a_l). We are going to track the minimum 
//      possible value of (l - 2a_l) in the variable min_odd whenever we update the odd indexes
//      in case #2 below. In this case, however, we need to update the even value, which ill
//      discuss in the next case (for odd indexes).
// 2.   Alright, so when the index is odd, you need to update the min_odd variable to see if
//      the current index can result in a value lower than the current value. You also need to
//      try seeing if using the current odd index along with the calculated even index would
//      result in a higher answer (desireable for alice). So, let's get into the math first:
//      Because we land on an off index, r must be odd, so l is even. The cost is still r-l.
//      The original equation would've been a_l-a_r (because even is addition and odd is 
//      subtraction), so the flipped equation is a_r-a_l. a_r-a_l - (a_l-a_r) would yield
//      2(a_r-a_l). The combined change (cost minus flipped equation) would be
//      r-l + 2(a_r-a_l). Rewritten, it would be (r + 2a_r) - (l + 2a_l). We know the r
//      value we are testing each time is the odd index we are currently iterating through,
//      and so the l value we are using is the even index previously optimized in step 1. 
//      Therefore, the variable min_even will track (l + 2a_l) because we want that value to
//      be minimized in order to acheive the maximum combined change (desirable for alice).

// Okay so a quick recap:
// - Each time we iterate over EVEN indexes, we use the even index as the r value in the 
// equation: (r - 2a_r) - (l - 2a_l) where (l - 2a_l) is the variable min_odd. We also
// update the min_even variable, which is the minimum of either itself or (l + 2a_l), 
// which is expanded on below.
// - Each time we iterate over ODD indexes, we use the odd index as the r value in the 
// equation: (r + 2a_r) - (l + 2a_l) where (l + 2a_l) is the variable min_even. We also
// update the min_odd variable, which is the minimum of either itself or (l - 2a_l), 
// which was expanded on above.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<long long> a(N);
        for (auto& i : a) cin >> i;

        // calculate the initial value of f(a) where cost is 0 & no moves have been made
        long long init = 0;
        for (int i{0}; i < N; ++i) {
            if (i % 2 == 0) init += a[i];
            else init -= a[i];
        }
        
        long long ans = init;   // updated with maximum answer

        // Process the case in which alice optimally swaps numbers of the same parity 
        // (both even or both odd) simply for an increase in cost
        // even # of items (Ex. N=4: +, -, +, - so picking indexes 0 and 2 is optimal,  
        // yielding 2-0 = 2, or N-2)
        // odd # of items (Ex. N=3: +, -, + so picking indexes 0 & 2 is optimal, yielding 
        // 2-0 = 2, or N-1)
        if (N % 2 == 0) ans += N-2;
        else ans += N-1;

        // Process the case in which alice swaps numbers w/ different parities
        long long min_even = LLONG_MAX, min_odd = LLONG_MAX/2;
        // Initialize with large placeholder values but divide by two to avoid overflow when subtracting
        // when i = 0 before the values have been updated
        for (int i{0}; i < N; ++i) {
            if (i % 2 == 0) {   // l is odd, r is even
                min_even = min(min_even, i + 2*a[i]);   // update min_even (l + 2a_l)
                ans = max(ans, init + (i - 2*a[i]) - min_odd); 
                // possibly update answer to initial answer + (r - 2a_r) - (l - 2a_l)
            } else {        // l is even, r is odd
                min_odd = min(min_odd, i - 2*a[i]);     // update min_odd (l - 2a_l)
                ans = max(ans, init + (i + 2*a[i]) - min_even); 
                // possibly update answer to initial answer + (r + 2a_r) - (l + 2a_l)
            }
        }

        cout << ans << endl;
    }
}
