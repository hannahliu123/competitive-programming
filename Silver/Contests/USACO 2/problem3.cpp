// USACO 2026 Second Contest, Silver
// Problem 3. Farmer John Loves Rotations

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> a(N);
    set<int> S;
    for (int i{0}; i < N; ++i) {
        cin >> a[i];
        S.insert(a[i]);
    }

    vector<int> right(N);
    map<int,int> cnt;   // number of each unique a[i]
    cnt[a[0]] = 1;
    int unique = 1;     // total uniqe items currently in the range [l,r]
    int r = 0;
    for (int l{0}; l < N; ++l) {
        while (unique < S.size()) {
            r++;
            cnt[a[r%N]]++;
            if (cnt[a[r%N]]==1) unique++;
        } right[l] = r-l;
        cnt[a[l]]--;
        if (cnt[a[l]]==0) unique--;
    }
    
    vector<int> left(N);
    cnt.clear();
    cnt[a[N-1]] = 1;
    unique = 1;
    int l2 = N-1;
    for (int r2{N-1}; r2 >= 0; --r2) {
        while (unique < S.size()) {
            l2--;
            cnt[a[(l2+N)%N]]++;
            if (cnt[a[(l2+N)%N]]==1) unique++;
        } left[r2] = r2-l2;
        cnt[a[r2]]--;
        if (cnt[a[r2]]==0) unique--;
    }

    for (int i{1}; i < N; ++i) {
        right[i] = min(right[i], right[i-1]+1);
    } for (int i{N-2}; i >= 0; --i) {
        left[i] = min(left[i], left[i+1]+1);
    }

    for (int j{0}; j < N; ++j) {    // all favorite indexes
        cout << min(right[j], left[j]);
        if (j != N-1) cout << ' ';
    } cout << endl;
}
