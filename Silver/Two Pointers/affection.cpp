// CF - C. An impassioned circulation of affection - R1600

// Start: 8:45
// End: 10:15       1 hr 30 mins

// ok so this took way too long. i mean i had the idea since pretty early kinda bc
// i already knew it was suppoused to be two pointers. the implementation was a real
// struggle tho. i think next time i wanna track the time where i figure out some kind
// of implementation idea. I already track start and end. imma track idea: from now on
// too. i kinda have a sleep headache rn so imma go to bed but imma be sure to upsolve
// tmr and like even reimplement it cos i have a ton of time tmrrrr~

// alright, so analyzing my code, i track the indexes of each letter in alp then for each
// query, i use two pointers to iterate through the array or indexes corresponding to the
// letter c. We go through that array 2 times (basically one then) so the time complexity
// is O(Q*max_size_of_array). the max size of an array will be N if the original string
// is purely one letter. therefore the time complexity is just O(Q*N) which is kinda a
// stretch because it'll result in a max of 3*10^8 operations

// holy moly bruh. my code is so inefficient omg. i didn't even need to make the alp vector!
// yeah bro if my code is O(QN) anyways, then why even bother shortening it???? ipasdbral
// aseirj alksdjrliaeruj alierujliajlajl bruh i could've just had such a clean and simple
// implementation!!!!! ok let's break down why i never even thought of that tho. for 
// starters i didn't think O(QN) was possible because that would be 3*10^8 max operations
// per test while the time limit is only 2 seconds. oh okay so the 10^8 operations per
// second rule is a conservative estimate. in reality it can fit up to 9*10^8 operations
// lol. well even if i knew that, i never even considered two pointers on the original
// vector before i calculated time complexities. i think i was too focused on making my
// code more efficient.

// lets start from the beginning. the gist of the problem is that you're given a string of
// letters and a number of operations you can make. your goal is to form the longest
// line of one letter where u can change a letter per each operation. if you know O(QN) works,
// for each query, all you need to do is decide which indexes to change within one loop of N.
// atp i think it's a pretty classic two pointers problem

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    string s;
    cin >> N >> s >> Q;

    vector<vector<int>> alp(26, vector<int>{});
    for (int i{0}; i < N; ++i) {
        alp[s[i]-'a'].push_back(i);
    }

    while (Q--) {
        int m;
        char c;
        cin >> m >> c;

        vector<int> a = alp[c-'a'];
        int l = 0, r = 0, cnt = m;  // cnt is how many changes remaining
        int ans = m, temp = 1;    // longest chain
        while (r < a.size()) {
            int cost = 0;   // cost to proceed to the next value
            while (r < a.size()-1) {  // increment r
                cost = a[r+1] - a[r] - 1;
                if (cnt < cost) break;  // can't connect the gap fully
                else {
                    temp += cost; temp++;   // includes the letter
                    cnt -= cost;
                    r++;
                }
            }
            
            if (cnt > 0) {  // apply extras
                ans = max(ans, min(temp+cnt, N));
            } else ans = max(ans, temp);
            if (r == a.size()-1) break;

            while (l < r && cnt < cost) {  // increment l
                l++;
                int ret = a[l] - a[l-1] - 1;
                temp -= ret; temp--;
                cnt += ret;
            } if (l==r && cnt<cost) { l++; r++; };
        }

        cout << ans << endl;
    }
}
