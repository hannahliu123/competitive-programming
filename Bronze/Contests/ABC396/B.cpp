#include <bits/stdc++.h>
using namespace std;

// nice

int main() {
    int Q;
    cin >> Q;

    vector<int> cards(100, 0);
    for (int i{0}; i < Q; ++i) {
        int q;
        cin >> q;
        if (q == 1) {
            int x;
            cin >> x;
            cards.push_back(x);
        } else {
            cout << cards[cards.size()-1] << '\n';
            cards.pop_back();
        }
    }
}
