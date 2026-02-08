// USACO 2024 January Contest, Silver
// Problem 1. Cowmpetency

// for this problem i still just dont have a good idea. like im leaning towards
// something with a prefix max array but idk how we can dynamically update that
// over each iteration, and then also when you update the value of one index,
// that affects the other ones too, so i thought if we could store the potential
// updates then apply them all in one go that might work? but no it doesntttt (i
// think) so uh. then i thought we could keep a running max as well but its not
// enoughghghghghgh. sigh editorial time

// oh and also this is p bad cos idek how to get the lower subtasks. i know those
// are just brute force, but like how do i even implement an N^2 solution?

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, Q, C;
        cin >> N >> Q >> C;

        vector<int> c(N);
        for (auto& i : c) cin >> i;

        while (Q--) {
            ;
        }
    }
}
