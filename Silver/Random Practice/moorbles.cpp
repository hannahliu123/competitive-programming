// USACO 2024 February Contest, Silver
// Problem 3. Moorbles

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
