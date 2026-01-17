// B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        bool pos = true;
        vector<int> a(N);
        for (int i{0}; i < N; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        int mex = 0;
        vector<bool> seen(N+1, false);
        vector<int> fw(N);  // mex forward
        for (int i{0}; i < N; ++i) {
            seen[a[i]] = true;
            while (seen[mex]) mex++;
            fw[i] = mex;
        }
        
        mex = 0;
        seen.clear();
        seen.resize(N+1, false);
        vector<int> bw(N);
        for (int i{N-1}; i >= 0; --i) {
            seen[a[i]] = true;
            while (seen[mex]) mex++;
            bw[i] = mex;
        }

        for (int i{0}; i < N-1; ++i) {
            if (fw[i] == bw[i+1]) {
                pos = false;
                break;
            }
        }

        if (pos) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
