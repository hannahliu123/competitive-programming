// C

// yaya i didnt actually know if this would tle or not :)

// wow okay so apparently the solution is much easier and my brute force prolly 
// should've have worked. At first, for each k, you each k candies with h hits and
// m misses such that h+m=k. For all the hits you have, you can eat one more candy.
// if that candy's a hit then your number of hits stays the same. if it's a miss then
// ur number of hits decreases. so, after you eat those k bags, you can only eat 
// h more misses.

// but you can simplify it even more. Because we start with h+m=k, then we take h
// more misses, we end up taking a total of m+h=k misses. so, we only stop taking
// candies if 1) we reached the end or 2) we took k misses. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; string S; cin >> N >> S;

    vector<int> misses(N+1,0);
    for (int i=1; i <= N; i++) {
        misses[i] = misses[i-1]+(S[i-1]=='x'? 1 : 0);
    }

    int pos = 1;
    for (int k=1; k <= N; k++) {
        while (pos < N && misses[pos] != k) pos++;
        cout << pos << '\n';
    }
}