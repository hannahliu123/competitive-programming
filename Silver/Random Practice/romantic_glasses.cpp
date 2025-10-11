// CF - E. Romantic Glasses - R1300

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<long long> a(N);
        for (int i{0}; i < N; ++i) {
            cin >> a[i];
            if (i % 2 == 1) a[i] *= -1;
        }

        vector<long long> pref = a;
        for (int i{1}; i < N; ++i) {
            pref[i] += pref[i-1];
        }

        set<long long> nums{0};
        bool found = false;
        for (int i{0}; i < N; ++i) {
            if (nums.find(pref[i]) != nums.end()) {
                cout << "Yes" << endl;
                found = true;
                break;
            }
            nums.insert(pref[i]);
        }

        if (!found) cout << "No" << endl;
    }
}
