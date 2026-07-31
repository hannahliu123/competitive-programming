// H. Reflect Sort - R1800

// Ohhh the trick to this problem is to notice what aspect/property of the array a never
// changes. In this case, the magnitude (abs val) of the difference between 2 consecutive
// elements will always stay the same (even if the number goes negative). Why? Well, in
// each iteration, notice that a_j becomes the same distance away from a_i except in the
// opposite direction (which i already noticed). because changes are applied to entire
// prefix and suffix subarrays, its guarenteed that neighboring elems/consecutive elems
// are either a_i or they're changed in the same "way" about the same a_i so their dist
// relative to eachother stays the same. 

// knowing this, the problem is reduced to minimizing the value of a[0] such that it's
// still positive (we don't need to guarentee the array is non decreasing). you can use
// math rearrangements to find that taking the prefix from x and y such that x is behind
// (to the right of y) in any order changes a_0 by 2(x-y). however, the relative distances
// between x and y could be changing unless theyre right next to eachother. then notice
// that we any distant difference can be decomposed into a sum of adjacent differences,
// changes in adjacent pairs are sufficient and optimal. 

// Now we know that we can increase/decrease a_0 by any 2(abs(x-y)) such that x and y are
// adjacent in a. We just need to find the combination that decreases a_0 as much as
// possible. This is where linear combinations and Bézout’s Identity comes in. so uh i
// never would've known this without reading the editorial, but basically if we have x
// numbers we can use to add/subtract from a_0, the gcd of all those numbers is the
// smallest increase/decrease we can make and all multiples of that number are all the
// possible increases/decreases we can make.  

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> a(N);
    long long sum = 0;
    int g = INT_MAX;
    for (int i=0; i < N; i++) {
        cin >> a[i];
        if (i>0) {
            int diff = abs(a[i]-a[i-1]);
            sum += (long long)diff;
            if (diff != 0) {
                if (g==INT_MAX) g = 2*diff;
                else g = gcd(g, 2*diff);
            }
        }
    }

    int mn = a[0] % g;
    if (mn==0) mn = g;

    cout << (long long)mn + sum << '\n';
}