// G

#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    int z{0};
    vector<int> A{};
    for (int i{0}; i < Q; ++i) {
        int y;
        cin >> y;

        int x = ((y + z) % 1000000000) + 1;
        A.push_back(x);
        sort(A.begin(), A.end());
    }

    return 0;
}
