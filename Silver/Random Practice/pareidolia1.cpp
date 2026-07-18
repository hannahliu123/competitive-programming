// USACO 2023 US Open Contest, Silver
// Problem 3. Pareidolia

// Start: 4:30
// Break: 5:40 - 9:30
// End: 10:12               1 hr 52 mins

// holy crap i did it omg that took way too long im gonna crash tf out holy wth man. i had
// the idea but then i had to tweak it a ton and im so freaking surprised it ended up
// working like holy moly man that was terrible. if that happened mid contest i would've
// been so cooked oml. 

// bro. im actually gonna crash out. are you kidding me rn. the actual solution is so
// annoyingly simple. bruh it's just a simple dp where vector<int> dp is size 6 and stores
// the number of substrings that are currently waiting for the ith letter of "bessie".
// At each index of the string S, we start a new substring, and at each index, we can
// potentially end any substring that was previously started and able to be ended. At any
// current index i, current_contribution (the running sum) represents the total number of 
// 'bessie' occurrences found if we consider all possible substrings that start anywhere
// to the left and end exactly at index i. Then at the end of every loop iteration, the code
// adds current_contribution to the final answer. If no new "bessie" is completed at index i,
// current_contribution does not change, but, we still add it to the final answer

#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    int N = S.length();

    vector<int> b{};
    vector<int> e{};
    vector<int> s{};
    vector<int> i{};
    for (int idx=0; idx < N; idx++) {
        if (S[idx]=='b') b.push_back(idx);
        if (S[idx]=='e') e.push_back(idx);
        if (S[idx]=='s') s.push_back(idx);
        if (S[idx]=='i') i.push_back(idx);
    }

    vector<pair<int,int>> v{};
    for (auto& idx : b) {
        auto it_e1 = upper_bound(e.begin(), e.end(), idx);
        if (it_e1==e.end()) break;
        auto it_s1 = upper_bound(s.begin(), s.end(), *it_e1);
        if (it_s1==s.end()) break;
        auto it_s2 = upper_bound(s.begin(), s.end(), *it_s1);
        if (it_s2==s.end()) break;
        auto it_i = upper_bound(i.begin(), i.end(), *it_s2);
        if (it_i==i.end()) break;
        auto it_e2 = upper_bound(e.begin(), e.end(), *it_i);
        if (it_e2==e.end()) break;
        
        v.push_back({idx, *it_e2});
    }

    long long ans = 0;
    long long sum = 0;
    unordered_map<int,long long> sums{};
    unordered_map<int,long long> contr{};
    int prev_start = -1, prev_end=-1;
    for (int idx=0; idx < v.size(); idx++) { // start, end
        int start = v[idx].first, end = v[idx].second;
        if (idx>0) ans += contr[prev_end]*(long long)(end-prev_end);
        // if (idx != v.size()-1 && v[idx+1].second == end) {
        //     continue;
        // }
        sum += (long long)(start-prev_start);
        contr[end] = sum;
        auto it = upper_bound(v.begin(), v.end(), make_pair(-1, start), 
            [](auto& a, auto& b) {return a.second < b.second;});
        if (it!=v.begin()) {
            it--;
            contr[end] += contr[(*it).second];
        }
        sums[end] = sum;
        prev_start = start;
        prev_end = end;
    } 
    ans += contr[prev_end]*(long long)(N-prev_end);

    cout << ans << endl;
}
