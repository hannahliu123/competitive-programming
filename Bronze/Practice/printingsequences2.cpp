// REDO #2 USACO 2025 February Contest, Bronze
// Problem 3. Printing Sequences

// Start: 7:59                  I watched videos & read the editorial BTW
// End: 

// The only reason I got this is because of that video... im so cooked

// K == 2: x*(y+z)=N        FINISHED AT: 8:17
//  REP x                   x is a factor of N
//      REP y               brute force all y
//          print ?
//      REP z               z = N/x - y
//          print ?

// K == 3: erm i give up. I would never have been able to solve this. Okay yeah
// i need SOO much more practice. The grind shall begin...

#include <bits/stdc++.h>
using namespace std;

vector<int> A;
int N, K;

string solve() {    // use a function because it makes things much simpler
    cin >> N >> K;
    A.resize(N);
    for (int i{0}; i < N; ++i) {cin >> A[i];}

    // different case based on K value (i could've thought of this because k is
    // limited to such few values; only three options!!!)
    if (K == 1) {
        return "YES";
    } else if (K == 2) {
        for (int x{1}; x <= N; ++x) {
            if (N%x != 0) continue;     // x isn't a factor of N
            for (int y{0}; y < N/x; ++y) {
                int z = N/x - y;
                vector<int> B{};
                vector<int> C{};
                for (int xx{0}; xx < x; ++xx) {     // create possible lists
                    for (int yy{0}; yy < y; ++yy) {
                        B.push_back(1);
                        C.push_back(2);
                    } for (int zz{0}; zz < z; ++zz) {
                        B.push_back(2);
                        C.push_back(1);
                    }
                } if (B == A || C == A) return "YES";
            }
        }
    } else if (K == 3) {
        return "SKIP";      // shhh
    } return "NO";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cout << solve() << '\n';
    }
}
