// G. Mixing MEXes - R1800

// Start: 8:26-8:35
// End: 

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;

        int lsum = 0;
        vector<int> l(N);
        vector<int> occ(1000001, 0);
        vector<pair<int,int>> def(N, {INT_MAX, INT_MAX});   // default mex, mex after gaining default mex
        vector<vector<int>> a(N);
        for (int i=0; i < N; i++) {
            cin >> l[i];
            lsum += l[i];
            vector<int> ai(l[i]);
            for (int j=0; j < l[i]; j++) {
                cin >> ai[j];
                occ[ai[j]]++;
            } sort(ai.begin(), ai.end());
            int mex = 0, mex2 = -1;
            for (int j=0; j < l[i]; j++) {
                if (mex2 == -1) {
                    if (ai[j] > mex) {
                        mex2 = mex+1;
                        if (ai[j]==mex2) mex2++;
                        else if (ai[j] > mex2) break;
                    } else if (ai[j]==mex) mex++;
                    if (mex2==-1 && j==l[i]-1) {
                        mex = ai[j]+1;
                        mex2=mex+1;
                    }
                } else {
                    if (ai[j] > mex2) break;
                    else if (ai[j]==mex2) mex2++;
                    if (j==l[i]-1) mex2 = ai[j]+1;
                }
            }
            def[i] = {mex, mex2};
            a[i] = ai;
        }

        long long ans = 0;
        for (int i=0; i < N; i++) {
            long long sum_less = 0;
            int cnt_less = 0;
            int x = occ[def[i].first];
            for (int j=0; j < l[i]; j++) {
                if (a[i][j] == def[i].first) x--;
                if (a[i][j] < def[i].first && ((j==0 || a[i][j] != a[i][j-1]) && (j==l[i]-1 || a[i][j] != a[i][j+1]))) {
                    cnt_less++;
                    sum_less += a[i][j];
                }
            } ans += (long long)(N-1)*((long long)def[i].first*(l[i]-cnt_less) + sum_less);
            ans += (long long)(def[i].second)*(x) + (long long)(def[i].first)*(lsum-l[i]-x);
            ans += (long long)(N-2)*(lsum-l[i])*(def[i].first);
        }

        cout << ans << '\n';
    }
}