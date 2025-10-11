// CF - C. Arrow Path - R1300

// Start: 11:37
// End: 12:12           got distacted but uh 35 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        string s1, s2;
        cin >> N >> s1 >> s2;

        pair<int, int> pos = {0, 0};
        bool possible = true;
        while (pos.first != 1 || pos.second != N-1) {
            if (pos.first == 0) {   // top
                if (s1[pos.second+1] == '<' && s2[pos.second] == '<') {
                    possible = false;
                    break;
                } else if (s1[pos.second+1] == '>') {
                    pos.second += 2;
                } else {
                    pos.first++;
                    pos.second++;
                }
            } else if (pos.first == 1) {    // bottom
                if (s2[pos.second+1] == '<' && s1[pos.second] == '<') {
                    possible = false;
                    break;
                } else if (s2[pos.second+1] == '>') {
                    pos.second += 2;
                } else {
                    pos.first--;
                    pos.second++;
                }
            }
        }

        if (possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
