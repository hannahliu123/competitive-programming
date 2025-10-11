#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;

    vector<int> hg{};   // H's in a row, G's in a row, repeat
    if (s[0] == 'G') hg.push_back(0);

    int cnt = 0;
    char prev = s[0];
    for (int i{0}; i < N; ++i) {
        if (s[i] == prev) {
            cnt++;
        } else {
            hg.push_back(cnt);
            cnt = 1;
        } if (i == N-1) {
            hg.push_back(cnt);
        }
        prev = s[i];
    }

    int ans = 0;
    int pos = 0;
    bool running = false;
    for (int i{0}; i < hg.size(); ++i) {    // i: even-H, odd-G
        if (i%2 != 0) {     // G
            if (hg[i]%2 != 0 && pos%2 == 0) {
                if (!running) {
                    ++ans;
                    running = true;
                }
            } else running = false;
        }
        pos += hg[i];
    }

    cout << ans << endl;
}

//  GGGHGHHGHHHGHG
// 03  112 13  111
