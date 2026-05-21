// USACO 2016 US Open Contest, Gold
// Problem 1. Splitting the Field

// Start: 9:25
// End: 10:24       59 mins

// WOOHOOO!!! ok this problem was def messier cos i slightly rushed the implementation 
// but im really glad i got the idea & figured this out on my own!! oh okay so there were
// weak test cases so i did actually miss a bit of logic. in this problem, cows can be
// located at the same x/y values, so you can't split an area between cows i and i+1 if
// they're located on the same x/y position. other than that i think my idea was spot
// on with the editorial :)). something that really helps imo is to first narrow the
// problem down as much as possible to greedy observations. then try to optimize code
// with certain algorithms

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);

    int N;
    cin >> N;

    vector<pair<int,int>> cowx(N);
    int xmin, xmax, ymin, ymax;
    for (int i=0; i < N; i++) {
        int x, y; cin >> x >> y;
        cowx[i] = {x, y};
        
        if (i==0) {
            xmin=x; xmax=x;
            ymin=y; ymax=y;
        }
        if (x > xmax) xmax = x;
        if (x < xmin) xmin = x;
        if (y > ymax) ymax = y;
        if (y < ymin) ymin = y;
    }

    long long area = (long long)(ymax-ymin) * (xmax-xmin);
    long long ans = 0;
    long long area1, area2;

    vector<pair<int,int>> cowy = cowx;
    sort(cowx.begin(), cowx.end());     // sorted by x
    sort(cowy.begin(), cowy.end(), [](auto& a, auto& b){  // sorted by y
        return a.second < b.second;
    });

    vector<vector<int>> pref(N, vector<int>(4));   // ymin, ymax, xmin, xmax
    pref[0] = {cowx[0].second, cowx[0].second, cowy[0].first, cowy[0].first};
    for (int i=1; i < N; i++) {
        pref[i][0] = min(pref[i-1][0], cowx[i].second);
        pref[i][1] = max(pref[i-1][1], cowx[i].second);
        pref[i][2] = min(pref[i-1][2], cowy[i].first);
        pref[i][3] = max(pref[i-1][3], cowy[i].first);
    }
    vector<vector<int>> suff(N, vector<int>(4));   // ymin, ymax, xmin, xmax
    suff[N-1] = {cowx[N-1].second, cowx[N-1].second, cowy[N-1].first, cowy[N-1].first};
    for (int i=N-2; i >= 0; i--) {
        suff[i][0] = min(suff[i+1][0], cowx[i].second);
        suff[i][1] = max(suff[i+1][1], cowx[i].second);
        suff[i][2] = min(suff[i+1][2], cowy[i].first);
        suff[i][3] = max(suff[i+1][3], cowy[i].first);
    }

    // group cows by x-value
    for (int i=0; i < N-1; i++) {
        // area1 from cow[0] to cow[i] inclusive
        
        // NOTE: You can't split between two cows if they're on the same x-value
        if (cowx[i].first == cowx[i+1].first) continue;
        
        int l = cowx[i].first - cowx[0].first;
        int h = pref[i][1] - pref[i][0];    // ymax - ymin
        area1 = ((long long)l) * h;
        l = cowx[N-1].first - cowx[i+1].first;
        h = suff[i+1][1] - suff[i+1][0];
        area2 = ((long long)l) * h;
        ans = max(ans, area-(area1+area2));
    }

    // group cows by y-value
    for (int i=0; i < N-1; i++) {
        // NOTE: You can't split between two cows if they're on the same y-value
        if (cowx[i].second == cowx[i+1].second) continue;

        int l = pref[i][3] - pref[i][2];   // xmax - xmin
        int h = cowy[i].second - cowy[0].second;
        area1 = ((long long)l) * h;
        l = suff[i+1][3] - suff[i+1][2];
        h = cowy[N-1].second - cowy[i+1].second;
        area2 = ((long long)l) * h;
        ans = max(ans, area-(area1+area2));
    }

    cout << ans << endl;
}
