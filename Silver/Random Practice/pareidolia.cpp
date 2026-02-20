// USACO 2023 US Open Contest, Silver
// Problem 3. Pareidolia

// erm so we dont have time rn so imma just forget about this problem and try to re
// solve it another day. im so frustrated that my idea didnt even freaking end up
// working. I need to NOT RUSH THE IMPLEMENTATIONNNNNNN and just double tripe
// quadriple check to make sure my solution works during contest. i cannot be wasting
// so much time like this omg

// ccbcessssicceecbebessieccbescsicee

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int N = s.length();

    string nxt = "bessie";
    int idx = 5;    // from 0-5
    vector<int> lastB{};
    for (int i{N-1}; i >= 0; --i) {
        if (s[i] == nxt[idx]) {
            if (idx==0) lastB.push_back(i);
            idx = (idx+5) % 6;
        }
    }

    vector<int> b{};    // span between each "bessie"
    vector<int> v{};
    idx = 0;
    int B = 0;      // number of total "bessie"
    int cnt = 0, start = -1, end = -1;
    for (int i{0}; i < N; ++i) {
        cnt++;
        if (s[i] == nxt[idx]) {
            if (idx==0) {
                if (lastB.empty() || i!=lastB.back()) continue;
                lastB.pop_back();
                v.push_back(cnt);
                cnt = 0;
            } if (idx==5) {
                B++;
                start = end;
                end = i;
                if (start!=-1) b.push_back(end-start);
            } idx = (idx+1)%6;
        }
    } if (b.size() < B) b.push_back(N-end);

    if (B==0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> suff(B, b[B-1]);
    for (int i{B-2}; i >= 0; --i) {
        suff[i] = suff[i+1] + b[i];
    }

    long long og = 0LL;
    for (int i{0}; i < B; ++i) {
        og += (long long)(i+1)*b[i];
    }
    
    long long ans = 0LL;
    for (int i{0}; i < B; ++i) {
        ans += og*v[i];
        og -= suff[i];
    }

    cout << ans << endl;
}
