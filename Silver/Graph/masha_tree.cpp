// CF - D. Masha and a Beautiful Tree - R1300

// Start: 9:02
// End: 9:31        29 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m;
        cin >> m;
        
        vector<int> p(m);
        for (auto& i : p) cin >> i;

        bool possible = true;
        int op = 0;
        while (p.size() > 1) {
            vector<int> new_p{};
            for (int i{0}; i < p.size(); i += 2) {
                if (p[i+1] == p[i] + 1) {    // good order
                    new_p.push_back(p[i+1]/2);
                } else if (p[i] == p[i+1] + 1) {    // flip order
                    op++;
                    new_p.push_back(p[i]/2);
                } else {    // impossible
                    possible = false;
                    break;
                }
            }
            p = new_p;
        }

        cout << (possible? op : -1) << endl;
    }
}
