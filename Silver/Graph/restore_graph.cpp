// CF - C. Restore Graph - R1800

// Start: 3:21
// End: 4:22        59 minutes

// this problem just had a ton of edge cases and i doubt i wouldn't 
// have gotten an accepted solution if i didn't have the ability to look
// at the test cases i missed. getting the idea was pretty easy whcih
// im proud of bc this was once again a very high leveled problem. idk im
// ever gonna look at ratings ever again istg bro (i probably will have
// to end up looking tho D:). anyways this problem was BFS although i didnt
// really realize that. i never use bfs over dfs so i guess that's why but
// i got to this answer relatively smoothly. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> d(N);     // distance, its own index
    for (int i{0}; i < N; ++i) {
        cin >> d[i].first;
        d[i].second = i;
    } sort(d.begin(), d.end());     // l -> g

    vector<pair<int,int>> ans{};
    bool pos = (d[0].first == 0? true : false);
    vector<vector<int>> options(N);
    vector<int> cnt(N, 0);  // how many nodes are connected to each
    options[0] = {d[0].second};
    int index = 0; // index of the option we are using
    for (int i{1}; i < N; ++i) {    // for each node (based on its distance)
        if (!pos) break;
        if (d[i].first != d[i-1].first) index = 0;
        if (d[i].first == 0 || d[i].first >= N || index >= options[d[i].first-1].size()) {
            pos = false; break;
        } options[d[i].first].push_back(d[i].second);   // add to its options

        while (cnt[options[d[i].first-1][index]] == K) {
            index++;
            if (index >= options[d[i].first-1].size()) {
                pos = false; break;
            }
        } if (!pos) break;
        ans.push_back({options[d[i].first-1][index], d[i].second});
        cnt[options[d[i].first-1][index]]++;
        cnt[d[i].second]++;
    }

    if (!pos) cout << -1 << endl;
    else {
        cout << ans.size() << '\n';
        for (auto& p : ans) {
            cout << p.first+1 << ' ' << p.second+1 << '\n';
        }
    }
}
