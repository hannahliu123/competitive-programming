// C - Bin Packing

// Start: 1:02
// End: 1:19        17 mins

// bruh tspmo what the heck do you mean presentation error. and why the 
// heckitydooda do we need to bring an extra like specifically BETWEEN 
// test cases like whattttt. why is the formatting harder than the problem
// bsfr right now isjlaksdjrlaierujanliuavlrfjdshfljkhkdsf

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, L; cin >> N >> L;
        vector<int> len(N);
        for (auto& i : len) cin >> i;

        sort(len.begin(), len.end());
        int l = 0, r = N-1;
        int bins = 0;
        while (l <= r) {
            if (len[r]+len[l] <= L) l++;
            bins++;
            r--;
        }

        cout << bins << '\n';
        if (t!=0) cout << '\n';
    }
}
