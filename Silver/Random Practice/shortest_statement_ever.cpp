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
// simple realizations. First, in binary arithmetic, the highest set bit in contributes
// overwhelmingly to the magnitude of the difference, so the leftmost choices we make
// matter much more than the right. If we start by setting p=x and q=y (the ideal senario)
// then greedily try to fix p and q such that p&q==0, we can arrive at the right answer.
// The two ways to adjust changing 1... to something with a 0 at that but is either to
// change it to 0111... (number decreases) or 1000... (the leftmost bit is added, so the
// number increases)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;

    }
}