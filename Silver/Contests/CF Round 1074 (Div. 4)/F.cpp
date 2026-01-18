// F

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {   // new test case
        int N, Q;
        cin >> N >> Q;

        vector<vector<int>> prefXOR(N, vector<int>{});
        for (int i{0}; i < N; ++i) {
            int x; cin >> x;
            prefXOR[0].push_back(x);
        } for (int i{1}; i < N; ++i) {    // each layer
            for (int a{0}; a < prefXOR[i-1].size(); a+=2) {
                prefXOR[i].push_back(prefXOR[i-1][a]^prefXOR[i-1][a+1]);
            }
        }

        while (Q--) {   // different cow gets a potion
            int index, newLevel;
            cin >> index >> newLevel; index--;
            
            for (int i{0}; i < N; ++i) {
                ;
            }
            // use prefix xor and loop from 1->N, resimulating only the ones a[index] participated in until it loses
        }
    }
}
