// USACO 2024 February Contest, Silver
// Problem 3. Moorbles

// so at first i implemented a competely wrong answer which was a HUUUGGGGE
// waste of time. it made me have no time to sovle the other problem which was
// annoying but my attention span was lowkey running out anyways. i hate when
// problems have such weak sample test cases but its pretty common so i need
// to be more aware of edge cases.

// okay so the fully solution is tricky because you never know if making some
// choice in turn t might cause you to lose later on. As a result, you need to
// know the minimum number of marbles you need left at each turn in order not 
// to die sometime in the future. The way i implemented this was with prefix 
// sum arrays and one issue was that you need to ensure that the marble count 
// doesn't drop to zero before reaching end because prefix sums only tracks 
// from some turn t to the end. I realized i could use another greedy idea and
// keep tracking the next minimum value and use that because without any +x,
// the prefix sums should be decreasing. it worked but i had to sort the array
// which took MlogM time. this could actually be implemented with suffix arrays
// to run in M time (technically MK but K is less than 4 so wtv). The problem is
// that im really really bad at recognizing and using suffix arrays because it
// isn't very intuitive to me and ive lowkey never practiced it. 

// This suffix idea works with taking the max of 1 or a negative number because
// say at turn 8 you needed 5 marbles to be alive and at turn 7 you get a minimum
// of 10 marbles. then that means at turn 6 you need -5 marbles. but of course
// if you actually ended up with -5 marbles, you'd lose, so you actually need 1
// marble just to stay alive at that point!!! this would be cleaner to implement

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<pair<int,int>> evenOdd(M);
        vector<int> mxPref(M+1);
        vector<pair<int,int>> sortedPref(M+1);
        for (int i{0}; i < M; ++i) {
            int mxOdd = -1, mxEven = -1, mnOdd = 1e9, mnEven = 1e9;
            for (int j{0}; j < K; ++j) {
                int x; cin >> x;
                if (x%2==1) {
                    mxOdd = max(mxOdd, x);
                    mnOdd = min(mnOdd, x);
                } else {
                    mxEven = max(mxEven, x);
                    mnEven = min(mnEven, x);
                }
            }

            int even = 0, odd = 0;
            if (mxOdd != -1) even = -1*mxOdd;
            else even = mnEven;
            if (mxEven != -1) odd = -1*mxEven;
            else odd = mnOdd;
            
            evenOdd[i] = {even,odd};
            mxPref[i] = max(even,odd);
            if (i>0) mxPref[i] += mxPref[i-1];
            sortedPref[i] = {mxPref[i],i};
        }
        mxPref[M] = mxPref[M-1];
        sortedPref[M] = {mxPref[M],M};

        sort(sortedPref.begin(), sortedPref.end());
        vector<int> mins{sortedPref[0].second};     // index of mins
        for (int i{1}; i <= M; ++i) {
            int curr = sortedPref[i].second, last = mins.back();
            if (curr > last) mins.push_back(curr);
        }

        bool pos = true;
        vector<char> ans(M);
        int currMn = 0;     // index = mins[currMn]
        for (int i{0}; i < M; ++i) {
            if (i >= mins[currMn]) currMn++;
            int op1 = evenOdd[i].first, op2 = evenOdd[i].second;
            int later = mxPref[mins[currMn]] - mxPref[i];
            if (N+op1 > 0 && N+op1+later > 0) {     // use even
                ans[i] = 'E';
                N += op1;
            } else if (N+op2 > 0 && N+op2+later > 0) {  // use odd
                ans[i] = 'O';
                N += op2;
            } else {
                pos = false;
                break;
            }
        }

        if (pos) {
            for (int i{0}; i < M; ++i) {
                cout << (ans[i]=='E'? "Even" : "Odd");
                if (i < M-1) cout << ' ';
            } cout << endl;
        } else cout << -1 << endl;
    }
}
