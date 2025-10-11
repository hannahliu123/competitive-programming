// Problem D

// Okay so i got the right idea of trying something for both letters then taking the minimum,
// but instead of trying to make the sides the same, the editorial tried to make the middle
// segment the same. 

// This is kinda just a logical greedy solution where if you want all a's in a continuous
// segment, you find all the positions of a's so all the indexes, then you take the median
// index, and all other a's will be placed around it. Then to calculate the cost of making 
// the segment around that value, for each index a exisits in, you take the distance from 
// the current index to the median index minus the offset value because they aren't just all
// placed ON the median. they are placed around it. they you total up those claculations for
// both a and b and take the min.

// mine works but i see how the editorial one is even simpler and more straightforward

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int N;
        string s;
        cin >> N >> s;

        // try moving all A's to the left
        int l = 0, r = N-1;
        vector<int> a;
        for (int i{0}; i < N; ++i) {
            if (s[i] == 'b') continue;
            a.push_back(i-l);
            l++;
        }

        // try moving all A's to the right
        int index = a.size()-1;
        long long a_ans = 0;
        for (int i{N-1}; i >= 0; --i) {
            if (s[i] == 'b') continue;
            a[index] = min(a[index], r-i);
            a_ans += a[index];
            index--; r--;
        }

        // try moving all B's to the left
        l = 0, r = N-1;
        vector<int> b;
        for (int i{0}; i < N; ++i) {
            if (s[i] == 'a') continue;
            b.push_back(i-l);
            l++;
        }

        // try moving all B's to the right
        index = b.size()-1;
        long long b_ans = 0;
        for (int i{N-1}; i >= 0; --i) {
            if (s[i] == 'a') continue;
            b[index] = min(b[index], r-i);
            b_ans += b[index];
            index--; r--;
        }

        cout << min(a_ans, b_ans) << endl;
    }
}
