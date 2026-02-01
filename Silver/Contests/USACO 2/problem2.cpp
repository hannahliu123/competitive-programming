// USACO 2026 Second Contest, Silver
// Problem 2. Declining Invitations

#include <bits/stdc++.h>
using namespace std;

long long ans;
// update which ranks are selected for criteria[loc[rank]] after rank is moved
void updateSelections(vector<int>& loc, vector<pair<int,vector<int>>>& criteria, int rank) {
    int& idx = criteria[loc[rank]].first;
    auto& ranks = criteria[loc[rank]].second;
    bool done = false;
    while (!done && idx < ranks.size()) {
        int rank2 = ranks[idx]; // see if rank2 can be selected
        if (loc[rank2] >= 0 && loc[rank2] > loc[rank]) {    // rank2 used somewhere else
            updateSelections(loc, criteria, rank2);
            done = true;
        } else if (loc[rank2] == -1) {  // perfect :)
            ans += (long long)rank2+1;
            loc[rank2] = loc[rank];
            done = true;
        } idx++;
    }
}

int main() {
    int N, C; cin >> N >> C;    // contestants, criteria
    
    vector<int> f(C);
    for (auto& i : f) cin >> i;
    vector<int> decline(N);
    for (auto& i : decline) cin >> i;

    // criteria i = {next index, {ranks}}        where i is 0-indexed
    vector<pair<int,vector<int>>> criteria(C, {0,{}});
    for (int i{0}; i < N; ++i) {    // rank i
        int num; cin >> num;
        while (num--) {
            int crit; cin >> crit; crit--;
            criteria[crit].second.push_back(i);
        }
    }

    ans = 0LL;
    vector<int> loc(N,-1);  // -1 = free, -2 = declined (dead), else = being used
    for (int i{0}; i < C; ++i) {    // for each criteria i
        int totalChosen = 0, mx = f[i];
        int& idx = criteria[i].first;
        auto& ranks = criteria[i].second;
        while (idx < ranks.size() && totalChosen < mx) {
            int rank = ranks[idx];  // see if we can select rank
            if (loc[rank] == -1) {  // perfect :)
                ans += (long long)rank+1;
                loc[rank] = i;
                totalChosen++;
            } idx++;
        }
    }

    for (int i{0}; i < N; ++i) {    // i contestants decline
        cout << ans << '\n';

        // contestant decline[i] declines (calculate the ans)
        int rank = decline[i]-1;    // rank that declines (becomes -2)
        if (loc[rank] >= 0) {   // used somewhere
            ans -= (long long)rank+1;
            updateSelections(loc, criteria, rank);
        } loc[rank] = -2;
    }
}
