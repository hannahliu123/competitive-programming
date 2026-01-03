// D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    map<int,set<int>> three;    // factor, {indexes}
    map<int,set<int>> five;
    map<int,set<int>> seven;
    for (int i{0}; i < N; ++i) {
        int x; cin >> x;
        if (x%3==0) three[x/3].insert(i);
        if (x%5==0) five[x/5].insert(i);
        if (x%7==0) seven[x/7].insert(i);
    }

    long long ans = 0;
    for (auto& j : five) {
        int factor = j.first;
        set<int> j5 = j.second;

        if (three.find(factor)==three.end() || seven.find(factor)==seven.end()) continue;
        set<int> k3 = three[factor];
        set<int> i7 = seven[factor];

        int ik = 0;
        for (auto& k : k3) {
            if (i7.count(k)) ik++;
        }
        int kcnt = k3.size() - ik;
        int icnt = i7.size() - ik;

        for (auto& x : j5) {  // for each index (to compare if j is max/min)
            int kbefore = distance(k3.begin(), k3.lower_bound(x));
            int kafter = k3.size() - kbefore;
            if (k3.lower_bound(x) != k3.end() && *k3.lower_bound(x) != x) kafter++;
            int ibefore = distance(i7.begin(), i7.lower_bound(x));
            int iafter = i7.size() - ibefore;
            if (i7.lower_bound(x) != i7.end() && *i7.lower_bound(x) != x) iafter++;
            else if (*k3.lower_bound(x) == x) ik--;

            long long a = (long long)ibefore*kbefore;
            long long b = (long long)iafter*kafter;
            ans += a + b - (long long)ik;
        }
    } 
    
    cout << ans << endl;
}
