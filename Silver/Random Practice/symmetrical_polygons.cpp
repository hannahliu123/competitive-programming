// CF - C. Symmetrical Polygons - R1500

// Start: 10:53
// End: 11:53       1 hour

// okay im actually so proud of my debugging skills for this problem.
// I got it wrong two times but each time i redid my code i made like
// a logical fix that i never thought of before and it ended up working
// out :DDD this time (literally the opposite of the problem i did earlier
// today) had not so great test cases so i had to make a ton of edits
// for newly-encountered edge cases. I kept my code really structured and
// all so im super duper proud of this hehe :DDD I think ill def switch 
// to 1600 by december and hopefully maybe even sometime during novemeber.
// but im also kinda busy this month esp over the weekends OH WAIT NO we
// have thanksgiving breka soon!!! so yeah maybe switch to 1600 at the
// start of break then start 1700 sometime throughout december. ach but
// the dec contest is like early december so ill only be on 1700 by then.
// I think ill aim to pass during january then cos during winter break i 
// can start 1800 and do some usaco-specific problems. i think ill be set
// if i can solve 1700 or 1800 problems so january is the goal!!!

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        map<long long, int> freq;
        for (int i{0}; i < N; ++i) {
            int x;
            cin >> x;
            freq[x]++;
        }

        set<int> odd;   // least -> greatest
        int sides = 0;
        long long total = 0;
        for (auto p : freq) {
            if (p.second % 2 == 0) {
                total += p.first*p.second;
                sides += p.second;
            } else {
                total += p.first*(p.second-1);
                sides += p.second-1;
                odd.insert(p.first); 
            }
        }

        if (total > 0) {
            int mx = 0, mx2 = 0;
            while (odd.size() > 0) {
                mx = *odd.rbegin();
                odd.erase(mx);
                mx2 = 0;
                if (odd.size() > 0) mx2 = *odd.rbegin();
                if (total+mx2 > mx) {
                    total += mx + mx2;
                    sides++;
                    break;
                }
            } if (sides < 3) total = 0;
        }

        cout << total << endl;
    }
}
