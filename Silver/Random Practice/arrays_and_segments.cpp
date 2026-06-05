// CF - E2. Array and Segments (Hard version) - R2100

// ugh so i spent over 1 hr and 30 mins on this but i got tle cos of the
// map using logM time complexity for insertion. i knew my time complexity
// within the loop would be M log M, but when i calculated it in desmos, i
// forgot the subscript of 2 (log_2) which actually makes a difference (ugh
// hey at least now ik). but either way i feel like we need to have some
// sorted data structure in that section because we dont know what order
// we might insert +1 or -1. ok wait actually becase we already have the mx
// array, we do know all the potential indexes that might be selected (cos
// they have to be at the edges of some segment!) or wait we can just make
// it size N+1 bruh

// omg okay this implementation got really messy and the time compexlity
// calculation was not it heh. im still glad i basically figured most of
// it out on my own tho :) AND HOLY MOLY THIS WAS R2100

// so basically i realized that for each a_i, if you try to find the max
// d value with a_i as the minimum, it would be optimal to select all 
// segments that contain a_i (because you can decrement it as much as 
// possible, and even if the segment includes the max value, it would 
// have a net contirbution of zero). so knowing this, i jad to calculate
// the max value after all segments were applied in O(M) time. to do this
// i used a difference array-similar method and i utilized the fact that
// there are only 300 total subsegments. thus, there can only be 600 max
// indexes where a subsegment starts/ends (all other indexes are not
// "important"). this idea is similar to coordinate compression in a
// sense. so for each "important" index, i tracked the maximum value
// within the regions that seperated those indexes, then during my loop
// i kept a difference array on all N items, but i knew i only had to
// check the 600 "important" indexes. the difference array tracked how
// many segments overlapped those regions, and i added the difference
// to the max value among those regions to find the new max.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> a(N);
    for (auto& i : a) cin >> i;

    set<int> idx{0,N};
    vector<pair<int,int>> seg(M);
    for (auto& p : seg) {
        cin >> p.first >> p.second;
        idx.insert(p.first-1);
        idx.insert(p.second);
        p.first--; p.second--;
    }

    vector<vector<int>> mx{};   // start, end, mx from start to end (inclusive)
    int prev = -1;
    for (auto& i : idx) {
        if (prev == -1) {
            prev = i; continue;
        }

        int currmx = -1000000;
        for (int j=prev; j < i; j++) {
            currmx = max(currmx, a[j]);
        } mx.push_back({prev, i-1, currmx});
        prev = i;
    }

    int d = 0;  // maximum value of max val - min val
    vector<int> ans{};
    for (int i=0; i < N; i++) {
        // try making a[i] the min & chosing all segments that decrease a[i]
        vector<int> chosen{};   // segments chosen
        vector<int> contr(N+1,0);
        for (int j=0; j < M; j++) {
            if (i>=seg[j].first && i<=seg[j].second) {
                chosen.push_back(j);
                contr[seg[j].first]--;
                contr[seg[j].second+1]++;
            }
        }

        int mnval = a[i]-chosen.size(), mxval = -1000000;
        int prev_contr = 0;
        for (int i=0; i < mx.size(); i++) {  // find mxval among all mx
            int start = mx[i][0], end = mx[i][1], val = mx[i][2];
            prev_contr += contr[start];
            mxval = max(mxval, val+prev_contr);
        }

        if (mxval-mnval > d) {
            d = mxval-mnval;
            ans = chosen;
        }
    }

    cout << d << '\n' << ans.size() << '\n';
    for (auto& i : ans) cout << i+1 << ' ';
    cout << endl;
}