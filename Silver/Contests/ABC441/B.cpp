// B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, Q;
    string S, T;
    cin >> N >> M >> S >> T >> Q;

    vector<bool> usedT(26, false);
    vector<bool> usedA(26, false);
    for (int i{0}; i < N; ++i) {
        usedT[S[i]-'a'] = true;
    } for (int i{0}; i < M; ++i) {
        usedA[T[i]-'a'] = true;
    }

    while (Q--) {
        string w;
        cin >> w;

        bool t = true, a = true;
        for (auto& c : w) {
            if (!usedT[c-'a']) t = false;
            if (!usedA[c-'a']) a = false;
        }

        if (t && !a) cout << "Takahashi" << endl;
        else if (a && !t) cout << "Aoki" << endl;
        else cout << "Unknown" << endl;
    }
}
