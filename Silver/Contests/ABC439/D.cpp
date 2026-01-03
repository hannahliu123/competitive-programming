// D

// be. so. fr. holy fridgsicles this is crazy. this is actually insane. this is absolutely
// bonkers. this is nuts. AHHHH BRO THESE TIME COMPLEXITIES ARE DRIVING ME INSAAAANE. ok
// so i literally had the right idea TWOOOOO times but some rando set operation just happens
// to take an eternity. bro i did not know distance took O(N) like wth man. oh and also i
// don't need ik beacause the factor will be a constant so it'll be impossible for and i,
// k, or j to land on the same spot. okay this was mb because if i accounted for that i 
// could've saved a lot of time and confusion. oh wow now i learned that map insertions
// are also O(logN) wth how did i never know this stuff?? i think atcoder prioritizes time
// complexity calculations a lot more than codeforces (lowkey i like codeforces way more
// after this competition but that prolly means i need to do more atcoder problems 🥲)

// okay a more efficient version of MY code (not editorial cos they implemented differently)
// is to use two pointers instead of binary search to get rid of the logN time stuff. I
// would still need to sort the vectors, but this approach is super clean and i really like
// it. basically for each index of the multiple of fives (the loop i already have), you
// start two pointers for 3 and 7 at 0 and then as the index of fives increase, you increase
// the pointers such that they're both still below the index of the five. this immediately
// gives you the before and after values!!

// Now let's do the dreaded time complexity calculation. in the worst case senario, each item
// is added to all three arrays (so it's a multiple of 3, 5, and 7). This takes O(3N) but
// that's the same as O(N). For sorting, it's important to realize that sorting one vector of
// size N is the same as sorting many vectors with a total size of N. WAIT. HOLD UP A MINUTE.
// BRO I DON'T EVEN NEED TO SORT IT OMGMGMGMGMMGMG. im missing so much obvious stuff today
// bro i literlaly created the vector in order so sorting is pointless bruhrurhrrhurhu. im
// literally gonna slap someone. okay whatever but either way inserting into a map takes logN
// time soooo total complexity is still O(NlogN)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    map<int,vector<int>> three;    // factor, {indexes}
    map<int,vector<int>> five;
    map<int,vector<int>> seven;
    for (int i{0}; i < N; ++i) {
        int x; cin >> x;
        if (x%3==0) three[x/3].push_back(i);
        if (x%5==0) five[x/5].push_back(i);
        if (x%7==0) seven[x/7].push_back(i);
    }

    long long ans = 0;
    for (auto& j : five) {
        int factor = j.first;

        if (three.find(factor)==three.end() || seven.find(factor)==seven.end()) continue;
        vector<int> k3 = three[factor];
        vector<int> i7 = seven[factor];

        for (auto& x : j.second) {  // for each index (to compare if j is max/min)
            auto it1 = lower_bound(k3.begin(), k3.end(), x);
            int kbefore = it1 - k3.begin();
            int kafter = k3.size() - kbefore;
            auto it2 = lower_bound(i7.begin(), i7.end(), x);
            int ibefore = it2 - i7.begin();
            int iafter = i7.size() - ibefore;

            long long a = (long long)ibefore*kbefore;
            long long b = (long long)iafter*kafter;
            ans += a + b;
        }
    } 
    
    cout << ans << endl;
}
