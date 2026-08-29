// ahh i should've noticed that if we're deailing with just two characters (in this case
// A and B), it makes like a million times easier to treat them as numbers (-1 and +1)

// uhh lets actually come backkk to this cos it needs a segtree

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q; string S;
    cin >> N >> S >> Q;
    
    while (Q--) {
        int type; cin >> type;
        if (type==1) {  // replace letter
            int i; char c; cin >> i >> c; i--;
            ;
        } else {
            int l, r; cin >> l >> r; l--; r--;
            ;
        }
    }
}