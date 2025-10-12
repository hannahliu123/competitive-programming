// CF - C. Rabbits - R1500

// Start: 10:13
// End: 11:02       49 mins

// ughhh i dont like this solution at all because its just so greedy and 
// loophole-y. ugh well the solution is greedy too but they have more logic
// and better implementation. I counded begin and end and they didn't do
// that. They only counted 1010101.. like me but they somehow used odd/even
// numbers of 0's? So they just went more sequentially but now i think mine
// is more logical to me at least. its kinda the same idea except mine has
// more variabels and code ig

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        string s;
        cin >> N >> s;

        bool pos = true;
        bool cont = false;
        int cnt = 0;
        int begin = -1, end = -1;
        for (int i{1}; i < N; ++i) {
            if (cont) { // 101...
                if (s[i] == '0' && s[i-1] == '1' && s[i+1] == '1') {
                    i++;
                    cnt++;
                } else {
                    cont = false;   // pattern ended
                    end = s[i]-'0';
                    if (begin==1 && end==1 && cnt%2==1) {
                        pos = false;
                        break;
                    } cnt = 0;      // reset
                }
            } else {    // not 101
                if (s[i] == '0' && s[i-1] == '1' && s[i+1] == '1') {
                    cont = true;
                    begin = ((i>=2)? s[i-2]-'0' : 1);
                    cnt++;
                    i++;
                }
            }
        }

        if (cont && begin==1 && cnt%2==1) {
            pos = false;
        }

        cout << (pos? "YES" : "NO") << endl;
    }
}
