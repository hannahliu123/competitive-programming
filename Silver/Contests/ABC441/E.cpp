// E

// i think i tried to rush to get to implementation too early for this problem 
// because i noticed that i was running out of time. i should've just focused on
// getting the idea instead. anyways my idea was based around prefix sums.

// okay so one way to solve this is by using fenwick trees, but i haven't learned
// that. i looked at a short video and uh it made zero sense. its very confusing to
// understand but i think it allows you to efficiently update a prefix sum array.

// so there's another slightly similar way to approach this problem. i was always
// looking at the prefix sum array from l->r. this was tricky because i chose a left
// value as a set/starting value and try to figure our how many values to the right 
// of it are valid (but obviously we havent visited those values on the right yet). 
// BUT! what if we still iterated from l->r except the RIGHT value was the set value
// and we just see how many previous ones satisfy it? using this logic, for each r
// value, you need to count the number of values before it that are less than it.
// logic wise, this is pretty much the same as what i thought of in the contest, just
// a bit more straightforward. it also doesn't solve the time complexity issue. the
// only good part is that we get to process all the numbers to the left of each r
// value but now we have to figure our how to further speed that up

// now let's figure out time complexity. it's important to realize that each value
// in the prefix sum will only change by at most 1 (because A, B, and C are 1, -1, or
// 0). because of this, if you're looking for values less than 3 and you already know
// the number of values less than 2, you can quickly compute the ones < 3 by adding
// the number of values equal to 2 to the ones less than 2. we can keep a vector
// "lessthan" where each index represents the number of items less than a certain value.
// you need to keep track of updates to each lessthan value. so whenever you update
// index i, you have to add the newly added numbers from index i-1 as well as current
// updates to index i. to this this, we can use a pair where the first value tracks
// old counts that were already updates to i+1. the second value can track newly added
// counts that need to be added when i+1 is processed. this means we can know the answer
// for each r value in O(1) time!! The only issue now is that there are both positive
// and negative values that we need to track for lessthan, but an index can only be 
// nonnegative. so, we should add N to each possible index. For example, if N=20,
// lessthan -20 will have an index of -20+20 = 0. 0 will have an index of 20. 20 will 
// have an index of 40. so we need to have indexes 0 through 2N available, meaning we
// we need lessthan to have a size of 2N+1. 
// **Quick edit: lessthan needs to have a size of 2N+2 because we also access the
// index of pref[i]+N+1 which is one after the current index. So if the current index
// was the last index, you would need one more slot

// yeah so i coded this out and it works and also makes sense to my brain lol. i think
// the way the editorial did it was actually more efficient now that i look at it where
// they use a variable to track the running sum. then you can subtract or add to that
// sum. The main point to really notice about this problem was that the prefix changes
// in increments of 1 or 0. lowkey very proud of this upsolving tho :D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<int> pref(N+1, 0);
    for (int i{0}; i < N; ++i) {
        int x = 0;
        if (S[i] == 'A') x = 1;
        else if (S[i] == 'B') x = -1;
        pref[i+1] = pref[i]+x;
    }
    
    vector<pair<int,int>> lessthan(2*N+2, {0,0});   // old, new
    long long ans = 0;
    for (int i{0}; i <= N; ++i) {
        auto& p = lessthan[pref[i]+N];   // old, new
        ans += p.first + p.second;

        lessthan[pref[i]+N+1].second += 1+p.second;
        p.first += p.second;
        p.second = 0;
    }

    cout << ans << endl;
}
