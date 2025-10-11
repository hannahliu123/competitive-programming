// CF - D. Productive Meeting - R1400

// I was SOOOO CLOSE! I don't even know how I overlooked this but all you had to freaking do
// was pair up the people with highest social levels first. This makes so much sense if you
// think about it (the editorial explanation lol) because you can always acheive N/2 convos
// unless the sum of all the social levels excluding the highest is lower than the highest. 
// Cos excluding that case, you either remain with people with 0 scoial levels remaining or
// one person with a social level of 1. The only case that person has higher that a social
// level of 1 is if it was that case i jtus said and the sum of all others was lower. SOOOO
// to acheive this, it makes sense to "use up" all the people with highest social levels 
// first so you're left with peopl with lower social levels and they can pair up with each
// other. If im gonna be so honest tho, i dont feel like i would come of with this logic
// and reasoning, but i mightve tested this solution and realized it worked. idk man

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        set<pair<int,int>> a{};     // least -> greatest
        for (int i{0}; i < N; ++i) {
            int x;
            cin >> x;
            if (x > 0) a.insert({x, i+1});    // 1-indexed
        }

        vector<pair<int,int>> ans{};
        while (a.size() > 1) {
            auto f = a.end(); --f;
            auto s = a.end(); --s; --s;
            pair<int,int> g1 = *f;
            pair<int,int> g2 = *s;
            a.erase(g1);
            a.erase(g2);
            ans.push_back({g1.second, g2.second});
            if (g1.first > 1) a.insert({g1.first-1, g1.second});
            if (g2.first > 1) a.insert({g2.first-1, g2.second});
        }

        cout << ans.size() << '\n';
        for (auto p : ans) cout << p.first << ' ' << p.second << '\n';
    }
}
