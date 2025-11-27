// USACO 2020 December Contest, Bronze
// Problem 3. Stuck in a Rut

// Start: 10:24
// End: 11:56       1 hr 32 mins

// ok man am i cooked or am i cooked. this was a BRONZE problem. I feel like doing
// else usaco problems is cooking my brain too much. is it just a mental thing? idk
// but i have a cf contest tomorrow and i feel like my ratings is gonna go doooooown.
// this is not very preppy at all. bro idk what's going on but i just can't think and
// peice together a solution for some reason. am i too used to simple greedy problems
// that i can't even implement algorithms anymore??? auhhghahahhghghhhtuhguhghgh oml
// i think imma take a break from uh usaco problems and go back to cf heh just to bring
// morale back up a bit. well see if i cook myself tmr tho bcos i have a bad feeling 
// imma do pretty bad :( bro the annoying thing is idek what's going on cos like i
// just feel like i can't think properly. like nothing makes sense and i keep missing
// details when i read the problems. ugh even easy problems seem sooo hard to me rn
// im so frustrated

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> cows{};    // d (0=north, 1=east), x, y
pair<int,int> findIntersection(int c1, int c2) {    // indexes of two cows
    if (cows[c1][0] == 0) { // c1 is north, intersect at x_c1, y_c2
        return {cows[c1][1], cows[c2][2]};
    } else {    // c2 is north, intersect at x_c2, y_c1
        return {cows[c2][1], cows[c1][2]};
    }
}

int main() {
    int N;
    cin >> N;

    vector<pair<pair<int,int>,int>> n{};
    vector<pair<pair<int,int>,int>> e{};
    cows.clear();
    cows.resize(N);
    for (int i{0}; i < N; ++i) {
        char d;
        int x, y;
        cin >> d >> x >> y;
        cows[i] = {(d=='N'? 0 : 1), x, y};
        if (d == 'N') n.push_back({{x,y}, i});
        else e.push_back({{y,x}, i});
    }

    sort(n.begin(), n.end());
    sort(e.begin(), e.end());

    set<pair<int,pair<int,int>>> intersect{};   // time, {c1,c2} where c1 is affected by c2 (c1 reaches the box after c2)
    for (auto& i : e) { // left
        int ie = i.second;
        int xe = i.first.second;
        int ye = i.first.first;
        for (auto& j : n) { // up
            int in = j.second;
            int xn = j.first.first;
            int yn = j.first.second;
            // intersect at xn, ye
            if (xn < xe || ye < yn) continue;   // no intersect
            int diste = xn-xe;
            int distn = ye-yn;
            if (diste > distn) {
                intersect.insert({diste, {ie, in}});
            } else if (distn > diste) {
                intersect.insert({distn, {in, ie}});
            }
        }
    }

    // intersect already sorted by least -> greatest time of intersect
    vector<int> ans(N, -1);
    vector<pair<int,int>> stop(N);      // where each cow stopped
    for (auto& i : intersect) {
        int time = i.first;
        int c1 = i.second.first;
        int c2 = i.second.second;
        if (ans[c1] == -1) {    // c1 not yet stopped
            if (ans[c2] == -1) {    // c2 still running forwards so intersect is valid
                ans[c1] = time;
                stop[c1] = findIntersection(c1, c2);
            } else if (cows[c2][0] == 0 && stop[c2].second >= cows[c1][2]) {  // c2 is north
                // check if c2 stopped but at or after the intersection so still valid
                ans[c1] = time;
                stop[c1] = findIntersection(c1, c2);
            } else if (cows[c2][0] == 1 && stop[c2].first >= cows[c1][1]) {  // c2 is east
                ans[c1] = time;
                stop[c1] = findIntersection(c1, c2);
            }
        }
    }

    for (int& i : ans) {
        if (i == -1) cout << "Infinity" << '\n';
        else cout << i << '\n';
    }
}
