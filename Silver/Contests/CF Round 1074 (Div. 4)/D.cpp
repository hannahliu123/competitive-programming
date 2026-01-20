// D

// this is where the contest started to get a bit chaotic. my first solution tle'd
// because i didn't know setting a vector equal to another vector toop O(N) time 
// where N is the size of the vector. then, i rush-implemented a solution that 
// didn't work before i finally figured out a working solution. my working solution
// was just keeping track of the last time the whole array was reset, but instead of
// actively resetting the whole array, I just stored the time value. the next time i
// came across an index that was updated before the most recent reset time, i would
// reset that value. i also had to make sure i reset the value at the very end in 
// case i didn't meet a certain index to reset it

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, M, H;
        cin >> N >> M >> H;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        vector<int> b(M);
        vector<int> c(M);
        for (int i{0}; i < M; ++i) {
            cin >> b[i] >> c[i]; b[i]--;
        }
        
        int wipe = -1;
        vector<pair<int,int>> a2(N);   // value, last update
        for (int i{0}; i < N; ++i) a2[i] = {a[i],-1};
        for (int i{0}; i < M; ++i) {
            if (wipe>a2[b[i]].second) a2[b[i]].first = a[b[i]]; // wipe
            a2[b[i]].second = i;
            a2[b[i]].first += c[i];
            if (a2[b[i]].first > H) {
                wipe = i;
                a2[b[i]].first = a[b[i]];
            }
        }

        for (int i{0}; i < N; ++i) {
            if (wipe>a2[i].second) a2[i].first = a[i]; // wipe
        }

        for (auto& i : a2) cout << i.first << ' ';
        cout << endl;
    }
}
