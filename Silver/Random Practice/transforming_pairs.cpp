// USACO 2025 February Contest, Silver
// Problem 3. Transforming Pairs

// I coded out the brute force solution (bfs kinda) which passed the first two test
// cases :')

// OHHH MY GOSH!!! for this problem, all you had to do is reframe the problem and 
// look at it in another way. instead of trying to acheive the solution from a & b,
// you want to work backwards and try to construct a & b FORM c & d. starting with
// c & d, at each step, you can only subtract one from another (the smaller one 
// from the larger one), so you just keep doing that until you get to the original a
// & b and keep track of the number of operations. BUT this is still too slow because
// you are tracking every single operation, so instead you want to perform subtractions
// in bulk (subtract one from another as much as possible using division) until the
// larger number becomes smaller than the old smaller number (then you swap and repeat).
// to prevent missing/skipping the original a & b values, you want to make sure you
// never 

// wow okay this implementation actually took a hot minute. i forgot if a value
// started below a or b then if u subtracted it would be negative heh. this makes sense
// tho. i think when i do the contest, when i come across a problem like this where im
// just so completely lost, i need to consider looping backwards (or often right to left)
// or some other approach. i should also really look at the constraints so i can 
// identify what to consider and what not to. that'll help me avoid wasting time on a 
// solution i already know won't work. i need to be very decisive when i eliminate
// possible answer methods

#include <bits/stdc++.h>
using namespace std;

int main() { 
    int t; cin >> t;
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        long long ans = 0LL;
        bool done = false;
        while (a!=c || b!=d) {
            if (done) {
                ans = -1;
                break;
            }

            if (c>d) {
                long long num = (c-a)/d;
                if (num <= 0) done=true;
                else {
                    ans += num;
                    c -= num*d;
                }
            } else {
                long long num = (d-b)/c;
                if (num <= 0) done=true;
                else {
                    ans += num;
                    d -= num*c;
                }
            }
        }

        cout << ans << endl;
    }
}
