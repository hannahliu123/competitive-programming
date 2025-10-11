// CF - D. Sharky Surfing - R1300

// Start: 9:25
// End: 10:05       40 mins

// Im preeeetty proud of this one cos I debugged it on my own this time lol and I actually
// figured it out first re-try! yip yip! k let's read the editorial now. HOLY MOLY THE
// EDITORIAL ALSO USED A PRIORITY QUEUE. If i wanted a bit better implementation I also 
// could've directly added everything to the priority queue first without sorting the
// powerups and possible using those first so it would've been cleaner. i also didn't need
// top store the powerups the way I did, and i could've just added all powerups that were
// infront of each hurdle to the priority queue. I would upsolve it, but there's not really
// much of a difference and I'm quite confident I know how to do that

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int h, p, end;
        cin >> h >> p >> end;

        vector<pair<int,int>> hurdles(h);
        for (int i{0}; i < h; ++i) {
            int l, r;       // start, end
            cin >> l >> r;
            hurdles[i] = {l, r};
        }

        int h_index{0};
        vector<vector<pair<int, int>>> powerups(h);
        for (int i{0}; i < p; ++i) {
            int x, v;       // position, value
            cin >> x >> v;

            while (x > hurdles[h_index].first) h_index++;
            if (h_index < h) powerups[h_index].push_back({v, x});    // value first
        }

        int k = 1;  // jump power
        int ans = 0;
        bool possible = true;
        priority_queue<int> available{};
        for (int i{0}; i < h; ++i) {
            sort(powerups[i].rbegin(), powerups[i].rend());     // G -> L
            int minimum = hurdles[i].second - hurdles[i].first + 2;
            for (int j{0}; j < powerups[i].size(); ++j) {
                if (k < minimum) {
                    if (!available.empty() && available.top() > powerups[i][j].first) {
                        k += available.top();
                        available.pop();
                        available.push(powerups[i][j].first);
                    } else {
                        k += powerups[i][j].first;
                    } ans++;
                } else available.push(powerups[i][j].first);
            } 
            
            while (!available.empty()) {
                if (k < minimum) {
                    k += available.top();
                    available.pop();
                    ans++;
                } else break;
            }

            if (k < minimum) {
                possible = false;
                break;
            }
        }

        cout << (possible? ans : -1) << endl;
    }
}
