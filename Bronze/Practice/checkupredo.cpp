// After looking at someone's explanation for a quicker solution
// https://www.youtube.com/watch?v=riOrKfxAHfQ

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("checkup.in", "r", stdin);
    //freopen("checkup.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> ans(N+1);
    vector<int> a(N);   // original species order
    vector<int> b(N);   // checkup species order

    for (int i{0}; i < N; ++i) {cin >> a[i];}
    for (int i{0}; i < N; ++i) {cin >> b[i];}

    int original{0};
    for (int i{0}; i < N; ++i) {
        if (a[i] == b[i]) ++original;
    }

    for (int middle{0}; middle < N; ++middle) { // odd
        int count{original};
        for (int i{0}; i <= min(middle, N-middle-1); ++i) {
            if (a[middle+i] == b[middle-i]) ++count;
            if (a[middle-i] == b[middle+i]) ++count;
            if (a[middle+i] == b[middle+i]) --count;
            if (a[middle-i] == b[middle-i]) --count;
            ans[count]++;
        }
    }

    for (int left{0}; left < N-1; ++left) { // even
        int count{original};
        for (int i{0}; i <= min(left, N-left-2); ++i) {
            if (a[left+i+1] == b[left-i]) ++count;
            if (a[left-i] == b[left+i+1]) ++count;
            if (a[left+i+1] == b[left+i+1]) --count;
            if (a[left-i] == b[left-i]) --count;
            ans[count]++;
        }
    }

    for (int num : ans) {
        cout << num << '\n';
    }
}
