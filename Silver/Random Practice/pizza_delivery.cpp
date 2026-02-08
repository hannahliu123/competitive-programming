// CF - F. Pizza Delivery - R1600

// k well this was a dp problem and i tried to solve it with a greedy solution.
// i ended up reading the editorial and i kinda get it. i should've just not
// implemented the greedy solution if i wasn't sure if it was gonna work. for
// these types of problems, i literally knew i had to use something like dp bc
// greedy almost (always) NEVER works. i technically havent really learned dp
// yet but i feel like ive indirectly used it sm. this solution is just checking
// all options depending on if you end on the max yvalue or min yvalue. this
// works because youre always keeping track of the min time it takes to get to 
// a certain point, and you keep track of all points that might be used. this
// way, you account for all options (and there aren't that many options, only
// four at each xvalue).

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, Ax, Ay, Bx, By;
        cin >> N >> Ax >> Ay >> Bx >> By;

        vector<int> x(N);
        for (int i{0}; i < N; ++i) cin >> x[i];
        map<int,pair<int,int>> pizzas;  // min, max y values
        int cnt = 0;
        for (int i{0}; i < N; ++i) {
            int y; cin >> y;
            if (pizzas[x[i]]==make_pair(0,0)) {
                pizzas[x[i]]={y,y};
                cnt++;
            } else {
                pizzas[x[i]].first = min(pizzas[x[i]].first, y);
                pizzas[x[i]].second = max(pizzas[x[i]].second, y);
            }
        } pizzas[Bx] = {By,By};

        long long ans = Bx-Ax;
        vector<pair<long long,int>> high(cnt+2, {0,Ay});  // ending on max (high)
        vector<pair<long long,int>> low(cnt+2, {0,Ay});   // min time, ending
        int i = 1;
        for (auto& p : pizzas) {
            int mn = p.second.first, mx = p.second.second;
            ans += mx-mn;
            int prevmn = low[i-1].second, prevmx = high[i-1].second;
            long long lotime = low[i-1].first, hitime = high[i-1].first;

            high[i].first = min(lotime+abs(prevmn-mn), hitime+abs(prevmx-mn));
            high[i].second = mx;
            low[i].first = min(lotime+abs(prevmn-mx), hitime+abs(prevmx-mx));
            low[i].second = mn;
            i++;
        }

        ans += min(high[cnt+1].first, low[cnt+1].first);
        cout << ans << endl;
    }
}
