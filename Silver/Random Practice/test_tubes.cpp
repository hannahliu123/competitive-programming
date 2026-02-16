// USACO 2024 February Contest, Silver
// Problem 2. Test Tubes

// For this problem, there were a series of greedy realizations you had to make, but in
// the end, the most important thing to notice would have been that you only ever want
// to empty the beaker ONE time (so it should only ever hold one color). this problem
// gets really complicated if you think about all the other factors (like what color
// should go on the bottom of what tube) but in the end the only thing that matters is
// that you choose to empty one tube (almost completely) first and you make sure that
// the color on the bottom of that tube is opposite of the color in the beaker. this is
// bc when u start to empty the next tube, you need a place to put each color. But ofc,
// if there is only one color at the bottom of a beaker, you don't want to remove it.
// another tricky part is figuring out which color should go on the bottom of which
// tube. notice that there are only two states. you could just try both options and take
// the minimum of those answers, but it actually doesn't matter as long as you satisfied
// the first condition above. i mean it would take a lot of drawing out test cases to
// allow you to permanently determine it doesn't matter, and you can't really figure that
// out with logic or math, soooo. well i guess it doesnt really matter because if they
// both end with the same color then they're basically the same, right? 

// if n = number of segments in tube0 and m = number of segments in tube1 then we must
// remove (n + m - 2) colors bc we are trying to reduce the total segments to just 2
// (one in each tube). but if the colors on the bottom are the same, we need to add one
// because we need to remove one of the bottoms too. also, if we need to use the beaker
// (more that one move originally necessary), then we also add one because the inital
// pour in the empty beaker doesnt remove any segments

// now to construct the final solution, all you need to do is compress the string, add
// a 1 or 2 to the bottom of one of the tubes if they have the same ending, add the top
// color to another top color if theyre the same (but make sure u dont make a tube empty
// so its safe to always start with the longer tube), then (tops should be different rn),
// choose a tube and put the top color in the beaker, then choose the tube with the 
// bottom color opposite of the one in the tube and empty it until the very last color. 
// Then do the same for the other tube. finally pour the beaker into that last tube

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> moves;

void compress(string& t) {
    string s = "";
    s += t[0];
    for (int i{1}; i < t.size(); ++i) {
        if (t[i] != t[i-1]) s+=t[i];
    } t = s;
}

void move(string& src, string& dst, int id1, int id2) {
    if (dst.empty()) dst.push_back(src.back());
    src.pop_back();
    moves.push_back({id1, id2});
}

void reduce(string& src, string& t, string& b, int srcID, int id) {
    while (src.size()>1) {
        char c = src.back();
        if (c==b[0]) move(src, b, srcID, 3);
        else move(src, t, srcID, id);
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N, P;
        string t1, t2;
        cin >> N >> P >> t1 >> t2;

        if (t1[0]==t2[0]) {
            t1 = (t1[0]=='1'? '2' : '1') + t1;
        }

        compress(t1);
        compress(t2);

        int ans = t1.size()+t2.size()-2;
        if (ans > 1) ans++;
        cout << ans << '\n';
        if (P==1) continue;

        moves = {};
        // tops are the same
        if (t1.back() == t2.back()) {
            if (t1.size() == 1) move(t2, t1, 2, 1);
            else move(t1, t2, 1, 2);
        }
        
        if (t1.size()>1 || t2.size()>1) {
            // move a color to the beaker
            string b = "";
            if (t1.size() > 1) move(t1, b, 1, 3);
            else move(t2, b, 2, 3);

            // determine which tube to reduce first
            if (t1[0] != b[0]) {
                reduce(t1, t2, b, 1, 2);
                reduce(t2, t1, b, 2, 1);
                move(b, t2, 3, 2);
            } else {
                reduce(t2, t1, b, 2, 1);
                reduce(t1, t2, b, 1, 2);
                move(b, t1, 3, 1);
            }
        }

        for (auto& i : moves) cout << i.first << ' ' << i.second << '\n';
    }
}
