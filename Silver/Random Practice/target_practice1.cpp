// USACO 2023 December Contest, Silver
// Problem 3. Target Practice

// Start: 4:19
// Break: 5:20 - 9:08
// End: 9:32                1 hr 25 min

// yayyaya im happy i ended up getting this one tho implementation and debugging was a
// nightmare. i forgot the fact that we need to make sure we aren't overcounting the number
// of targets we fire at cos u can only shoot a target down once. also implementation in
// general was really wacky

// a more understandable way to do this is to have a pref array answer for how many are
// hit in the prefix then a suffix like i did for each of 4 operation increments/decrements.
// i need to be careful about overlap tho which i did. lowkey im pretty surprised i ended up
// figuring out all those overlap issues

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, C; cin >> T >> C;
    unordered_set<int> t{};
    for (int i=0; i < T; i++) {
        int x; cin >> x;
        t.insert(x);
    } string s; cin >> s;

    int ans = 0;
    int pos = 0;
    unordered_map<int,int> finl{};
    for (int i=0; i < C; i++) {
        if (s[i]=='F') {
            finl[pos]++;
            if (finl[pos]==1 && t.count(pos)==1) ans++;
        } else if (s[i]=='L') pos--;
        else if (s[i]=='R') pos++;
    }
    
    vector<int> p1(C, 0);
    vector<int> p2(C, 0);
    vector<int> m1(C, 0);
    vector<int> m2(C, 0);
    unordered_map<int,int> rem = finl;
    unordered_map<int,int> bkwd{};
    for (int i=s.length()-1; i > 0; i--) { // backwards
        p1[i-1] = p1[i];
        p2[i-1] = p2[i];
        m1[i-1] = m1[i];
        m2[i-1] = m2[i];
        if (s[i]=='F') {
            bkwd[pos]++;
            rem[pos]--;
            if (t.count(pos)==1 && rem[pos] == 0) {    // check if later F could've occupied it now
                if (bkwd[pos+1]>0) m1[i-1]++;
                if (bkwd[pos-1]>0) p1[i-1]++;
                if (bkwd[pos+2]>0) m2[i-1]++;
                if (bkwd[pos-2]>0) p2[i-1]++;
            }
            // first F on this pos, new pos is a target, new pos not earlier occupied
            if (bkwd[pos]==1 && t.count(pos-1)==1 && rem[pos-1]==0) m1[i-1]++;
            if (bkwd[pos]==1 && t.count(pos+1)==1 && rem[pos+1]==0) p1[i-1]++;
            if (bkwd[pos]==1 && t.count(pos-2)==1 && rem[pos-2]==0) m2[i-1]++;
            if (bkwd[pos]==1 && t.count(pos+2)==1 && rem[pos+2]==0) p2[i-1]++;
        } else if (s[i]=='L') pos++;
        else if (s[i]=='R') pos--;
    }

    pos = 0;
    int curr_ans = 0;
    unordered_map<int,int> curr{};
    for (int i=0; i < s.length(); i++) {
        int ans2 = curr_ans;
        if (s[i]=='F') {
            // replace with L or R
            ans2 += max(p1[i], m1[i]);

            curr[pos]++;
            if (curr[pos]==1 && t.count(pos)==1) curr_ans++;
        } else if (s[i]=='L') {
            // replace with R
            ans2 += p2[i];
            // replace with F
            if (finl[pos-1]-curr[pos-1]==0 && curr[pos]==0 && t.count(pos)==1) {  // firing now increases ans
                ans2 = max(ans2, curr_ans+1+p1[i]);
            } else ans2 = max(ans2, curr_ans+p1[i]);
            pos--;
        } else if (s[i]=='R') {
            // replace with L
            ans2 += m2[i];
            // replace with F
            if (finl[pos+1]-curr[pos+1]==0 && curr[pos]==0 && t.count(pos)==1) {   // firing now increases ans
                ans2 = max(ans2, curr_ans+1+m1[i]);
            } else ans2 = max(ans2, curr_ans+m1[i]);
            pos++;
        } ans = max(ans, ans2);
    }

    cout << ans << endl;
}