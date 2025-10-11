// Static Range Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    vector<long long> prefix{0};
    long long sum{0};
    for (auto& i : a) {
        cin >> i;
        sum += i;
        prefix.push_back(sum);
    }
    
    while (Q--) {
        int l, r;
        cin >> l >> r;

        cout << prefix[r]-prefix[l] << '\n';
    }
}
