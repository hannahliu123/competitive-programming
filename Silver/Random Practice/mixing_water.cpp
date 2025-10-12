// CF - C. Mixing Water - R1700

// bro bro bro bro bro BROOOOOOOO omg. So many mistakes holy moly (hey
// but i learned a ton of stuff so wtv). Okay first of all never use
// division to compare values. cross multiply instead. Second i thought
// i messed up the implementation somehow but no it was that autistic
// stupid fricking equals sign (UGHGGHGGHG). And third i was confused 
// with time limits and integer overflow but i think i figured the
// long long stuff out. this problem made determining an uppeer bound
// for hi very hard cos all u know is that H C and T are less than 1e6.
// But how can you determine the value of hi then? i used 100000 and it 
// worked but USACO Guide used INT_32MAX which is like over 1000000000.
// I didn't realize binary serach was log N (i thought it was N log N) 
// and so i tried using 100 at first to account for the test case. This
// is one of the rare problems where you don't even have an N so you
// don't need ot loop through anything whatsoever. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long H, C, T;
        cin >> H >> C >> T;

        // Try 1 to 1 ratio
        if (H+C >= 2*T) {
            cout << 2 << endl;
            continue;
        }

        // Binary search on cups of hot water
        int hi = 1000000, lo = 1;
        while (hi > lo) {
            if (lo+1 == hi) break;
            int mid = lo+(hi-lo)/2;
            long long num = H*mid + C*(mid-1);
            long long den = (2*mid)-1;

            if (num >= den*T) { // too hot (add more water)
                lo = mid;
            } else if (num < den*T) {  // too cold (less water)
                hi = mid;
            }
        }

        // try both lo & hi
        long long num1 = (H*(lo)+C*(lo-1)) - T*(lo+lo-1);
        long long den1 = (lo+lo-1);
        long long num2 = T*(hi+hi-1) - (H*(hi)+C*(hi-1));
        long long den2 = (hi+hi-1);
        if (num1*den2 <= num2*den1) cout << lo+lo-1 << endl;
        else cout << hi+hi-1 << endl;
    }
}
