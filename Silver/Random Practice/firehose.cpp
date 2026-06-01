// DM::OJ - CCC '10 S3 - Firehose

// bro tspo because tell me why i cant just start from the gap??? ig for problems
// like these if you have extra time (like the limits are't that strict) then we
// might as well just check all senarios idk man

#include <bits/stdc++.h>
using namespace std;

int H, K;
vector<int> h;

bool check(int mid) {
    for (int i=0; i < H; i++) {
        int idx = i;    // start from house i
        int end = (i==0? H-1 : i-1);

        for (int j=0; j < K; j++) {
            int reach = h[idx] + 2*mid;
            while (h[idx] <= reach) {
                if (idx == end) return true;

                idx++;
                if (idx==H) {
                    idx = 0;
                    reach -= 1e6;
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> H;
    h.resize(H);
    for (int i=0; i < H; i++) {
        cin >> h[i];
    } cin >> K;

    sort(h.begin(), h.end());   // l->g

    // bin search on min hose length (true if we can use <K hoses with a length of mid)
    int lo=0, hi=1e6;
    while (lo < hi) {
        int mid = (lo+hi)/2;

        if (check(mid)) hi = mid;
        else lo = mid+1;
    }

    cout << lo << endl;
}