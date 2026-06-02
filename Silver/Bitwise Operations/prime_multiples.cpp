// CSES Problem Set - Prime Multiples

// Start: 10:09
// End: 10:44       35 mins

// Okay so i got the idea but there were some slight specifics i didn't catch (the
// long long issue and also even and odd). So about long longs, i knew it was a 
// problem but i didnt know if i just needed a larger data type or something. the
// actual fix was very elegant. I knew if mult > N at any point, we could break out,
// and i know mutl only increases when we multiply it by a[i]. So, before we even
// multiply, we can check, if mult > N/a[i], and if so, we would know we should break
// and set mult = N+1. 

// The other specific was that my original idea was just to add all numbers divisible
// by each individual value in a[i] then subtract any overlap by subtracting all 
// multiples of size >1 of values from a. however, that over subtracts overlap and i 
// didn't realize that. Okay so obviously, iIf we consider each prime individually and
// find the number of multiples it has, we will find that there is an overlap for each
// number that is a multiple of two primes. But, i didn't notice that this subtraction
// would have an overlap for each number that is a multiple of three primes. For 
// example, 30 = 2*3*5, so originally we would count 3 copies of 30. then for the pairs
// 23, 25, and 35, we would subtract 3 copies of 30. so for the group 235, we should
// add back 30 (so in general, we should add back the number of integers that are
// multiples of three primes). then this pattern of adding and subtracting continues
// for even and odd numbers of values in the subset. This is referred to as the
// Inclusion-Exclusion Principle. This is easier to understand if you visualize the
// intersections as a venn diagram and you just want the area of the 1D layer of the
// entire diagram. First you would add A+B+C. but now there is an extra layer of overlap
// beween A&B, B&C, and A&C so you subtract each of those once. Before subtracting that 
// tho, there were three layers of overlap on A&B&C. However, after you subtracted those,
// you also removed all three layers over A&B&C, so now you need to add it back. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N; int K;
    cin >> N >> K;
    vector<long long> a(K);
    for (auto& i : a) cin >> i;

    long long ans = 0;
    for (int mask=1; mask < (1<<K); mask++) {
        long long mult = 1;
        for (int i=0; i < K; i++) {
            if (mask & (1<<i)) {    // a[i] is selected
                if (mult > N/a[i]) {
                    mult = N+1;
                    break;
                } mult *= a[i];
            }
        }
        
        
        if (__builtin_popcount(mask) % 2 == 0) {
            // even number of 1s (repeated)
            ans -= N/mult;
        } else {
            // odd number of 1s (unique)
            ans += N/mult;
        }
    }

    cout << ans << endl;
}
