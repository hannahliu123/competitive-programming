// B. Shortest Statement Ever - R1800

// Ive thought for 48 mins and im stuck. I know for sure this is just a bitwise problem
// and ive been playing around with bitwise subtraction. Ive come up with a greedy idea
// that we just need to use one of the numbers then construct the best possible other
// number but I can't prove why it would work and i dont want to go through the process
// of figuring out how to construct that other number if this solution doesn't even work

// first i kinda narrowed down the problem strictly to greedy observations & binary
// patterns/operations. binary serach didn't really work, so i should've focused on greedy.
// my intuition of setting p or q to x or y actually works, but the proof is very 
// complicated. Once i narrowed this down to binary & greedy, I should've made some 
// simple realizations. 

// First, looking at the binary representations of x and y from left to right, obviously
// we don't want to touch anything that doesn't have a conflict (both positions have a 1).
// Additionally, the highest set bit (leftmost) in will contribute overwhelmingly to the
// magnitude of the difference, so our job is just to make the difference caused by that
// bit as small as possible no matter what. If we start by setting p=x and q=y (the ideal
// senario), there are 2 ways to do this:
// 1.   Increase the magnitude of p/q. So, using p as an example, if the conflict occured
//      at ...1..., we change p to ..10..., which minimizes the difference because we set
//      everything after that MSB to zero. After this, q can remain the same, but we do
//      need to check/confirm that p&q=0 because it's possible we messed up something to
//      the left of the MSB
// 2.   Decrease the magnitude of p/q. Using p as an example, if the conflict occured at
//      ...1..., we change p to ...01.., which minimized the difference because we set
//      everthing after the MSB to 1. After this, q must have everything after the MSB
//      set to 0 to guarentee p&q=0
// Using this strategy, the absolute difference of p-x or q-y will always be less than or
// equal to 2^b where b is the MSB conflict. 

// Thus, it is reasonable to conclude this answer is optimal because we must no matter
// what resolve the conflict at the MSB and so if we do it in the two ways that minimize
// the difference at the MSB, one answer is guaranteed to be optimal

// I definitely don't think I would've gotten this, because even now after breaking down
// and understanding the editorial, I still have small doubts about how this works fully.
// I mean in contest if i had a ton of time left and didn't care about penalties, I guess
// i might try it :/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        if ((x&y)==0) {
            cout << x << ' ' << y << '\n';
            continue;
        }

        int mn_diff = INT_MAX;
        int p, q;    
        for (int i=29; i >= 0; i--) {   // find the leftmost conflict
            if (x&(1<<i) && y&(1<<i)) {
                // Increase p/q
                int p1 = (x>>(i)<<(i))+(1<<i);
                if (p1-x < mn_diff && (p1&y)==0) {
                    mn_diff = p1-x;
                    p=p1; q=y;
                }
                int q1 = (y>>(i)<<(i))+(1<<i);
                if (q1-y < mn_diff && (x&q1)==0) {
                    mn_diff = q1-y;
                    p=x; q=q1;
                }

                // Decrease p/q
                p1 = (x>>i<<i) - 1;
                q1 = y>>i<<i;
                if (abs(p1-x)+abs(q1-y) < mn_diff) {
                    mn_diff = abs(p1-x)+abs(q1-y);
                    p=p1; q=q1;
                }
                p1 = x>>i<<i;
                q1 = (y>>i<<i) - 1;
                if (abs(p1-x)+abs(q1-y) < mn_diff) {
                    mn_diff = abs(p1-x)+abs(q1-y);
                    p=p1; q=q1;
                }

                break;
            }
        }
        
        cout << p << ' ' << q << '\n';
    }
}