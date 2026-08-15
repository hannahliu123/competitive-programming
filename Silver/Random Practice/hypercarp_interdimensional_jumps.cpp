// D. Hypercarp and Interdimensional Jumps - R1800

// okay I got stuck in a loop of just trying to brute force this in a way by looking for a
// pattern but that just got really messy and tedious pretty quickly and now im braindead.
// we can't do a naive dp because x and y go up to 10^8. we should somehow simulate or 
// compute the jumps because it tells us there will be <= 2*10^4. omg i overcomplicated
// things so much because i drew the freaking graph wrong at first then i didn't double
// check until i was too far in. because of that, for some reason i thought the final move
// didn't need to increment a or b aesrhhsghkasdr. 

// Okay so you can quickly notice that the moves you can make go in a patter such that the
// sum of coordinates of a valid end point must equal k(k+1)/2 (sum of consecutive integers).
// Knowing this, you want to find the previous k(k+1)/2 value less than or equal to the curr
// x+y for that test case. For the specific coordinate that is closest to (x,y) such that the
// sum of the coordinates is d=(k(k+1)/2), we want to move diagonally from (x,y) to the bottom
// left. But the better way to do this is actually taking the midpoint of (d-y,y) and (x,d-x)
// which works if you visualize it. if it's a decimal, we take the integer points to the left
// and right. if any coordinate is negative, just replace it with zero (closest but not ideal).

// once we have out ending point, we need to reconstruct the answer. Here, you need to kinda
// visualize 

// okay for this problem, i just wish i didn't spend so long staring at it. It wasn't like i
// wasn't making progress (cos i was) but it was just very slow and i didn't really know where
// my thoughts were heading. I also needed to relate these pattern-based ideas to actual math

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;

        ;
    }
}