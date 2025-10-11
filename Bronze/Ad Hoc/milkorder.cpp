// Level: Hard
// US Open 2018 Problem 2

// Ok so i don't think ive ever passed the time or memory limit... so that might
// be a problem in the future. But this is like THE messiest code I've ever
// written so we don't talk about that. I had to write if statements for so many
// cases I didn't account for and that's why it looks like... this heh. This took
// over an hour (maybe like 1.5 hrs) so that's not very slay

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> socialOrder(M);
    vector<int> positions(N);

    int order1{0};
    for (int i{0}; i < M; ++i) {
        cin >> socialOrder[i];
        if (socialOrder[i] == 1) order1 = i+1;
    }
    for (int i{0}; i < K; ++i) {
        int c, p;
        cin >> c >> p;

        if (c == 1) {
            cout << p << endl;
            return 0;
        }

        positions[p-1] = c;
    }

    int controlPos{N};
    if (order1) {
        for (int social{0}; social < order1-1; ++social) {
            bool exists{false};
            int existsPos;
            for (int pos{0}; pos < N; ++pos) {
                if (positions[pos] == socialOrder[social]) {
                    exists = true;
                    existsPos = pos;
                    break;
                }
            }

            if (!exists) {
                for (int pos{0}; pos < N; ++pos) {
                    if (positions[pos] == 0) {
                        positions[pos] = socialOrder[social];
                        break;
                    }
                }
            }
            
            if (exists) {
                for (int i{0}; i < existsPos; ++i) positions[i] = -1;
            }
        }
    } else {
        for (int social{static_cast<int>(socialOrder.size()) - 1}; social >= 0; --social) {
            bool exists{false};
            for (int pos{0}; pos < N; ++pos) {
                if (positions[pos] == socialOrder[social]) {
                    exists = true;
                    break;
                }
            }
            
            if (!exists) {
                for (int pos{controlPos-1}; pos >= 0; --pos) {
                    if (positions[pos] == 0) {
                        positions[pos] = socialOrder[social];
                        break;
                    }
                }
            }
            
            for (int i{0}; i < N; ++i) {
                if (positions[i] == socialOrder[social]) {
                    controlPos = i;
                    break;
                }
            }
        }
    }
    
    for (int i{0}; i < N; ++i) {
        if (positions[i] == 0) {
            cout << i+1 << endl;
            break;
        }
    }
}
