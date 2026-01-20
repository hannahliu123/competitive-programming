// F

// i ran out of time to solve this problem, but i came up with a really good idea
// (lowkey finalized the idea in bed lol) but now i wanna test/implement it!!

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {   // new test case
        int N, Q;
        cin >> N >> Q;

        vector<vector<int>> prefXOR(N, vector<int>{});  // xor of each group w/o potions
        for (int i{0}; i < 1<<N; ++i) {
            int x; cin >> x;
            prefXOR[0].push_back(x);
        } for (int i{1}; i < N; ++i) {    // each layer
            for (int a{0}; a < prefXOR[i-1].size(); a+=2) {
                prefXOR[i].push_back(prefXOR[i-1][a]^prefXOR[i-1][a+1]);
            }
        }

        while (Q--) {   // different cow gets a potion
            int index, newLevel;
            cin >> index >> newLevel; index--;  // 0-indexed
            
            int above = 0, inc = 1, oldLevel = prefXOR[0][index];
            for (int i{0}; i < N; ++i) {    // simulate each game cow w/ potion is in
                int currXOR = prefXOR[i][index] ^ oldLevel ^ newLevel;
                if (index % 2 == 0) {   // fight with right
                    if (currXOR < prefXOR[i][index+1]) {  // loses
                        above += inc;
                    }
                } else if (currXOR <= prefXOR[i][index-1]) {  // fight left & loses
                    above += inc;
                }
                inc *= 2;     // the number of cows in each group during next round
                index /= 2;
            }

            cout << above << endl;
        }
    }
}
