// C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    set<int> viewAll{};
    vector<set<int>> check(200001);
    for (int i{0}; i < Q; ++i) {
        int type, X;
        cin >> type >> X;

        if (type == 1) {
            int Y;
            cin >> Y;
            check[X].insert(Y);
        } else if (type == 2) {
            viewAll.insert(X);
        } else {    // 3
            int Y;
            cin >> Y;

            if (viewAll.count(X)) {
                cout << "Yes" << '\n';
            } else {
                if (check[X].count(Y)) {
                    cout << "Yes" << '\n';
                } else cout << "No" << '\n';
            }
        }
    }

    return 0;
}
