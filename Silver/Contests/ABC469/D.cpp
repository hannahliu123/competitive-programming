// D

// evaluating two pairs was really pointless. idk why i didn't just decide to evaluate
// the first pair because obviously one of them would have to be in a pair.
// this was another case of me not being sure my solution works before jumping into
// implementation. One edge case i missed is that even if some player doesn't appear in
// the finals, if player x appears every time, you could pair x with some nonexistent
// player and that would be valid. Another edge case is when two players are in every
// single final. Then, x can pair with N-1 other players and y can pair with N-2 (cos
// we don't double count x and y)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<pair<int,int>> v(M);
    for (int i=0; i < M; i++) {
        cin >> v[i].first >> v[i].second;
    }

    set<pair<int,int>> ans{};
    int final_ans = 0;
    vector<int> try_num{v[0].first,v[0].second};
    for (auto& a : try_num) {  // try a
        int a_cnt=0;
        int op1=-1, op2=-1;
        for (int i=0; i < M; i++) {
            if (v[i].first==a || v[i].second==a) {
                a_cnt++;
            } else {
                if (op1==-1) {
                    op1 = v[i].first;
                    op2 = v[i].second;
                } else {
                    if (v[i].first!=op1 && v[i].second!=op1) {
                        op1 = -2;
                    } if (v[i].first!=op2 && v[i].second!=op2) {
                        op2 = -2;
                    }
                }
            }
        }
        if (op1 > 0) ans.insert({min(a,op1), max(a,op1)});
        if (op2 > 0) ans.insert({min(a,op2), max(a,op2)});
        if (a_cnt == M) final_ans++;
    }

    if (final_ans == 0) final_ans = ans.size();
    else if (final_ans == 1) final_ans = N-1;
    else final_ans = 2*N-3;
    cout << final_ans << '\n';
}