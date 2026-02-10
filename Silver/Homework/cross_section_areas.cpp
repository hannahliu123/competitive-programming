// F - Areas on the Cross-Section Diagram

// okay so this took WAY longer than i would've liked. i got the answer pretty 
// quickly but couldn't figure out how to determine when to combine pools even
// tho the answer was so simple and straight-forward. i complicated things way too
// much and i wasn't on to anything. bro u literally just need to check if the 
// previous x value was less. i was busy looking at y values omg. i think i just
// overcomplicated it way too much. im gonna try to structure my thinking more
// next time

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    vector<int> down{};   // x, y
    vector<pair<int,int>> ans{};    // area, start-xval
    int i = 0, total = 0;
    for (auto& c : s) {
        if (c=='\\') down.push_back(i);
        else if (c=='/') {
            int last = -1;  // last x value of a '\'
            if (!down.empty()) {
                last = down.back();
                down.pop_back();
            } if (last >= 0) {
                int area = i-last;
                total += area;
                if (ans.empty()) ans.push_back({area, last});
                else {
                    while (!ans.empty() && last < ans.back().second) {
                        area += ans.back().first;
                        ans.pop_back();
                    } ans.push_back({area,last});
                }
            }
        } i++;
    }

    cout << total << '\n' << ans.size();
    for (auto& i : ans) cout << ' ' << i.first;
    cout << endl;
}
    