// C

// bro idk how tf i didn't realize this but i literally know i could solve this if i
// could just find a way to check if a sequence of length x was possible. bruh im so
// pissed. if i iterate over every possible length then try to find a sequence of that
// length it's an O(N^2) solution. it's important to realize here that binary serach is
// NOT an option because we need a fixed length in order to find the solution so we can
// greedily chose each item. if we know the length then we know the left rank and right
// rank as we're building our sequence from left to right. if we did binary serach, just
// because of length of 5 works doesn't mean a length of 3 will work. If we checked if a
// lenght of x or more was possible, then length is no longer fixed so its not a monotonic
// function. UGFHHHHH

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> l(N);
        vector<int> r(N);
        vector<int> u(N);
        vector<int> v(N);
        for (int i=0; i < N; i++) {
            cin >> l[i] >> r[i] >> u[i] >> v[i];
        }

        int ans = 0;
        for (int len=1; len <= N; len++) {
            // check if a sequence of this len is possible
            int left=1, right=len;
            bool pos = false;
            for (int i=0; i < N; i++) {
                if ((left<l[i] || left>r[i]) && (right<u[i] || right>v[i])) {
                    left++; right--;
                } if (left==len+1 && right==0) {
                    pos = true;
                    break;
                }
            } if (pos) ans = max(ans, len);
        }
        
        cout << ans << '\n';
    }
}