// CF - B. Chocolate - R1300

// Start: 10:00
// End: 10:33       33 mins

// brocowski this should've taken so much shorter but i didn't notice i used ++i instead
// of --i in my for loop then i never realized I needed to ust long longs... didn't think
// N <= 100 would need it but guess I was wrong. Let's see why tho

// Oh okay so a more clever solution would've been just to use the indexes of each 1 (nut)
// instead of remove the front and end then count the zeroes. Could've just multipled by
// index of 1 - prev index of 1. wow that's so much simpler

// The maximum solution to this problem would be when N = 100 (because obviously the more
// peices, the more possible breaks). If you evenly split the nuts with gaps inbetween, you
// can either use gaps of 1 empty one resulting in 2^50 (beacause each nut has 2 options and
// there will be 50 nuts and 50 non-nuts). You could also have 3^33 (2 empty ones between 
// each), or 4^25. The maximum is 3^33, which results in approximately 5e15 (needs long long)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a{};
    bool leading = true;
    for (int i{0}; i < N; ++i) {
        int c;
        cin >> c;

        if (leading && c == 0) continue;
        else {
            leading = false;
            a.push_back(c);
        }
    }

    bool tailing = true;
    for (int i{(int)a.size()-1}; i >= 0; --i) {
        if (tailing && a[i] == 0) a.pop_back();
        else {
            break;
        }
    }

    if (a.empty()) {
        cout << 0 << endl;
        return 0;
    }

    int zero_cnt = 0;
    long long ans = 1LL;
    for (int i{0}; i < a.size(); ++i) {
        if (a[i] == 1) {
            ans *= (long long)(zero_cnt+1);
            zero_cnt = 0;
        } else {
            zero_cnt++;
        }
    }

    cout << ans << endl;
}
