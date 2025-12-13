// D. Magazine Ad - R1900

// Start: 2:26
// End: 3:14        48 mins

// Most of this time was spent just trying to figure out how to do the input. 
// The idea was really simple and i think ive pretty conforateable with 
// implementing binary search now. Ive very comfortabel with it. i just find
// it hard to realize when a problem wants binary search every now and then.
// HOLY MOLY 1900 is crazy. yeah im never looking at ratings ever again wtf
// this wasnt even hard

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    string s;
    getline(cin>>ws, s);
    vector<int> ad{};   // characters
    int start = 0;
    for (int i{0}; i < s.length(); ++i) {
        if (s[i] == '-' || s[i] == ' ') {
            ad.push_back(i-start);
            start = i+1;
        } else if (i == s.length()-1) {
            ad.push_back(i-start+1);
        }
    }

    int hi = 1e6, lo = s.length()/k;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int curr = 0, rows = 1;
        bool pos = true;
        for (int i{0}; i < ad.size(); ++i) {
            int add = (i != ad.size()-1? ad[i]+1 : ad[i]);  // space or dash
            if (curr+add > mid) {
                curr = add;
                rows++;
                if (add > mid || rows > k) {
                    pos = false;
                    break;
                }
            } else curr += add;
        }

        if (pos) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << endl;
}
