// USACO 2025 US Open Contest, Silver
// Problem 3. Ski Slopes

// YAYAYYA OMG IT WORKED!!! this took me like at least 2 hours but uh A WIN IS A WIN!
// YESSSS MY LOGIC IS LIKE SPOT. ON. WITH THE EDITOIRAL WHO LET ME COOK!?!?!?!?!?

#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> adj;
vector<vector<int>> slope;
// c[i] = {{mx difficulty of this slope for c=i, enjoyment}, ...} where 0<=i<=10
vector<vector<pair<int,long long>>> c;

void dfs(int node, int prev, vector<int> d, long long e) {
    sort(d.rbegin(), d.rend());   // g -> l
    int lowest = 0;
    if (!d.empty()) lowest = d.back();
    bool d_full = (d.size() == 11);
    vector<int> copy = d;

    for (auto& i : adj[node]) {
        if (i[0] != prev) {
            bool changed = false;
            if (!d_full || lowest < i[1]) {
                if (d_full) copy.pop_back();    // remove lowest
                copy.push_back(i[1]);   // add new difficulty
                changed = true;
            }

            dfs(i[0], node, copy, e+(long long)i[2]);

            if (changed) {
                copy.pop_back();    // remove added difficulty
                if (d_full) copy.push_back(lowest);
            }
        }
    }

    // use d to create c[i] where i goes from 0->10 
    for (int i=0; i < 11; i++) {    // c = i
        // max when c = i is d[i]
        if (i >= d.size()) c[i].push_back({0, e});
        else c[i].push_back({d[i], e});
    }
}

int main() {
    int N; cin >> N;
    adj.resize(N);
    for (int i=1; i < N; i++) {
        int p, d, e;    // end, difficulty, enjoyment
        cin >> p >> d >> e; p--;
        // from i to p (but we insert the opposite)
        adj[p].push_back({i, d, e});
    }

    c.resize(11);
    dfs(0, -1, {}, 0);

    vector<vector<long long>> prefMx(11, vector<long long>(N));   // enjoyments
    for (int i=0; i < 11; i++) {
        sort(c[i].begin(), c[i].end());
        for (int j=0; j < N; j++) {
            prefMx[i][j] = c[i][j].second;
            if (j>0) prefMx[i][j] = max(prefMx[i][j], prefMx[i][j-1]);
        }
    }
    
    int M; cin >> M;
    while (M--) {
        int skill, courage;
        cin >> skill >> courage;
        
        auto it = lower_bound(c[courage].begin(), c[courage].end(), make_pair(skill+1, 0LL));
        int idx = it - c[courage].begin();
        idx--;

        cout << prefMx[courage][idx] << '\n';
    }
}
