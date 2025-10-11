// Problem D - UPSOLVE AFTER CONTEST

// So i read the editorial and was VERY confused but i thiiiink i got it so lets try to uh
// solve this thing. So during the contest, i kinda had the idea to go in a specific order, 
// but I really only thought of going forward/backward and quickly realized that wouldn't
// work. So the actual solution involves going through each element from smallest -> highest.
// Start with 1. You can either keep it or flip it to the highest possible number (resulting
// in a inversion count of the number of items before that index or after because all are
// guarenteed to be larger). Then, you REMOVE that index from p and you go to 2. Notice that
// wether you flipped 1 or not, it WILL NOT affect any items after it! This is the part that
// I missed! Think about it:
// If you kept 1 the way it is, then obviously nothing would change. BUT if you flipped it, 
// the you're already counting all the inversions that it causes (by taking the number of 
// items to the right of it considering that all numbers lower have been removed). Even if
// later on, there is a number that is flipped (and becomes higher) that occurs to the right
// of another numbe ryou flipped eariler, it is guarenteed that the new flipped number will
// still be less than the previously flipped one, resulting in no new inversions! 

// Because of this logic, all you need to do is process the numbers from the lowest -> 
// highest original value! If you don't want the hassle of removing the numbers, you could
// also just calculate the numbers to the left/right that are greater for each index 
// considering that all the lower numbers wouldn't been processed and removed by the time you
// got to the new number. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<int> p(N);
        for (int i{0}; i < N; ++i) cin >> p[i];
        
        // precomupte for each index i the number of items greater than i to its left & right
        vector<int> greater_left(N, 0);
        vector<int> greater_right(N, 0);
        for (int i{0}; i < N; ++i) {
            for (int j{0}; j < N; ++j) {
                if (i == j) continue;
                if (j < i) {    // to the left
                    if (p[j] > p[i]) greater_left[i]++;
                } else {        // to the right
                    if (p[j] > p[i]) greater_right[i]++;
                }
            }
        }

        // you could've done this in the loop above and not have had to keep track of the
        // vectors greater_left and greater_right (like in the editorial's solution), but this 
        // approach makes it easier to understand what's going on
        int ans = 0;
        for (int i{0}; i < N; ++i) {
            ans += min(greater_left[i], greater_right[i]);
        }

        cout << ans << endl;
    }
}
