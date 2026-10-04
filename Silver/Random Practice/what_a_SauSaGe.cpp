// B. What a SauSaGe! It's All Meat - R1500

// I spent 30 mins on this but ended up deciding to read the editorial. The problem is
// essentially asking us how many items we can make divisible my three by applying
// operations to adjacent elements. Now the KEY for this problem is that a_i < 16, 
// meaning theres's a maximum of 4 bits. Of those values, it is desireable to make all
// a_i either 0, 3, 6, 9, 12, or 15. Also, whenever we apply an operation, we must do
// it on two adjacent items. as a result, you can essentially apply the operation in
// pairs only (non-adjacent) because you can overlap 2 xors to revert to the original
// value. If you combine multiple xors, you can notice that your options are essentially
// xor 0, 3, 5, 6, 9, 10, 12, or 15. Now you also need to notice that all possible
// operation xors have an even number of 1 bits in their binary representations. As a
// result, all operations maintain the parity of the number of bits turned on because
// it either turns two bits on, two bits off, or one on and one off (does nothing to 
// parity). Thus, only a_i with an even popcount originally will possibly become
// divisible by 3. For those a_i, you can just xor it with itself. If there's any a_i
// with an odd popcount, you can pair all operations with that a_i because it doesn't
// have a chance at being divisible by 3 anyways. If all a_i have an even popcount, you
// can pick the first a_0 as the dummy pair. At the end, all items will be 0 except a_0
// which will be either a multiple of 3 or 5 or 10. If it's 5 or 10, you can pair it with
// a 0 and xor it with 3 to keep both divisible by 3. Thus, it can be proven all items
// with an even popcount can eventually become divisible by 3

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, Q; cin >> N >> Q;
        vector<int> a(N);
        int ans = 0;
        for (auto& i : a) {
            cin >> i;
            if (__builtin_popcount(i)%2==0) ans++;
        } cout << ans << ' ';        

        while (Q--) {
            int p, x; cin >> p >> x; p--;
            ans -= (__builtin_popcount(a[p])%2==0);
            a[p]=x;
            ans += (__builtin_popcount(a[p])%2==0);
            cout << ans << ' ';
        } cout << '\n';
    }
}
