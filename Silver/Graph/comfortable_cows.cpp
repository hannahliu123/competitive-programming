// USACO 2021 February Contest, Silver
// Problem 1. Comfortable Cows

// Start: 5:32
// End: 7:01        1 hr 29 mins

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> cows;
vector<vector<int>> field; // -1 if empty, 0-4 if cow
vector<pair<int,int>> v;
int ans;

void add_cow(int x, int y) {
    ans++;  // new cow added
    int adj = 0;    // number of cows adjacent to cow at x,y
    for (auto& [a,b] : v) {
        if (field[x+a][y+b] >= 0) { // there's a cow adjacent
            adj++;
            field[x+a][y+b]++;
        }
    } field[x][y] = adj;

    // NOTE: the loop above MUST come first & be seperate from the loop below
    // or else adjacent cows will not be properly updated because you try to fix
    // cows with seemingly 3 adjacent neighbors. Stop trying to make your code more
    // compact & efficient in these senarios without checking if it might break
    // your logic!!

    for (auto& [a,b] : v) {
        if (field[x+a][y+b] >= 0) { // there's a cow adjacent
            if (field[x+a][y+b] == 3) { // need to add another cow
                for (auto& [a2,b2] : v) {
                    if (a+a2==0 && b+b2==0) continue;   // same as cow x,y
                    if (field[x+a+a2][y+b+b2] == -1) add_cow(x+a+a2,y+b+b2);
                }
            }
        }
    }

    if (adj == 3) {
        for (auto& [a,b] : v) {
            if (field[x+a][y+b] == -1) add_cow(x+a,y+b);
        }
    }
}

int main() {
    int N; cin >> N;
    cows.resize(N);
    field.resize(3000, vector<int>(3000, -1));
    for (int i=0; i < N; i++) {
        // x,y from 1000-2000
        int x, y; cin >> x >> y; x+=1000; y+=1000;
        cows[i] = {x, y};
    }

    ans = 0;
    v = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    for (int i=0; i < N; i++) {
        int x = cows[i].first, y = cows[i].second;
        if (field[x][y] == -1) {    // new cow on empty space
            ans--;  // adding cow x,y doesn't count towards the ans
            add_cow(x,y);
        } else {
            ans--;  // real cow replaces a cow that had to be added
        }

        cout << ans << '\n';
    }

    ;
}
