// C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    
    set<int> seen{};
    set<int> invalid{};
    for (int i{1}; i*i+(i+1)*(i+1) <= N; ++i) {
        for (int j{i+1}; i*i+j*j <= N; ++j) {
            int ans = i*i+j*j;
            if (seen.count(ans)) invalid.insert(ans);
            else seen.insert(ans);
        }
    }

    cout << seen.size() - invalid.size() << '\n';
    for (auto& i : seen) {
        if (!invalid.count(i)) cout << i << ' ';
    } cout << endl;
}
