// CF - D. Rae Taylor and Trees (easy version) - R1400
// CF - F. Rae Taylor and Trees (hard version) - R1600

// I had to read the editorial for this one because i got stuck thinking there might
// be a way to brute force recreate the tree. I looked at the easy version editorial
// and it does make a lot of sense. essentially, you want to track the minimum prefix
// and the maximum suffix of permutation p. You know there will be a path from p[i]
// to p[i+1] if the prefix minimum at that i is less than the suffix maximum at i+1.
// This is because you know the value of p[i] is either greater than or equal to the
// current prefix minimum. that means there's definitely a way to go from the prefix
// minimum to i (or it already is the min). from there, you can definitely go to
// some other point in permutation p (later on) because the suffix maximum is greater
// than the prefix minimum (meaning there's a value in p after index i that is 
// greater than the current p[i]). Otherwise, it's impossible.

// Now for the hard version, we need to construct the tree. If we already know it's
// possible, you just connect the value at the prefix minimum to the next value at
// the suffix maximum. this connects some value before or at i to some value after
// i. but if that was already connected (meaning that the prefix value was before i),
// then you would just want to connect i to the prfix minimum (which is already 
// connected to the next suffix maximum. doing this for the entire permutation will
// guarentee all nodes are connected. 

// Okay so the implementation for this problem was super duper easy, I just couldn't
// figure out the prefix and suffix logic even though it seems so simple. I think 
// it's because i was so conviced the answer had to do with graph traversal and
// reconstruction and i didn't really think of prefix sums (or in this case prefix
// minimums and suffix maximums). i feel like im relatively familiar with this concept
// tho so im a little sad i didn't get it. i guess i needed to visualize the problem
// different instead of drawing edges. i should've approached it with a more logic-
// based approach because the logic isn't even that hard

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> p(N);
        for (auto& i : p) cin >> i;
        
        vector<int> prefMin(N, p[0]);
        vector<int> suffMax(N, p[N-1]);
        for (int i{1}; i < N; ++i) {
            prefMin[i] = min(p[i], prefMin[i-1]);
        } for (int i{N-2}; i >= 0; --i) {
            suffMax[i] = max(p[i], suffMax[i+1]);
        }

        bool pos = true;
        set<pair<int,int>> tree{};
        for (int i{0}; i < N-1; ++i) {
            int mn = prefMin[i], mx = suffMax[i+1];

            if (mn > mx) {
                pos = false;
                break;
            } if (!tree.count({mn, mx})) {
                tree.insert({mn, mx});
            } else tree.insert({mn, p[i]});
        }

        cout << (pos? "Yes\n" : "No\n");
        if (pos) {
            for (auto& p : tree) cout << p.first << ' ' << p.second << '\n';
        }
    }
}
