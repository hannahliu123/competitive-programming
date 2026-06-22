// CSES Problem Set - Counting Divisors

#include <bits/stdc++.h>
using namespace std;

// oh an even more optimized way is to count how many of each PRIME factor makes
// up the number. For example, 18 is made up of one 2 and two 3s. Using those 3
// options, we can make 6 different numbers (which are the 6 factors of 18): 
// 1, 2, 3, 6, 9, 18. So, we are basically looking for the number of unique integer
// combinations we can make by multiplying 1 or more of our prime factors. Because
// 2 appears one time, when we create factors we can either use 2 zero times or one
// time (so 2 options for the number 2). Similarly, we have 3 options for the number
// 3 because we can use it 0, 1, or 2 times. Notice that the default value is 1, so
// if we don't use 2 or 3, we aren't left with 0 (rather 1, which is valid). thus,
// the answer is the product of all (number_of_times_some_prime_number_is_a_factor + 1)

int main() {
    int N; cin >> N;
    
    int MX = 1000000;
    vector<int> largestPrimeFactor(MX+1, 0);
    for (int i=2; i <= MX; i++) {
        if (largestPrimeFactor[i] == 0) {   // i is prime
            for (int j=i; j<=MX; j+=i) {
                largestPrimeFactor[j] = i;
            }
        }
    }

    while (N--) {
        int x; cin >> x;

        int ans = 1;
        while (x > 1) {
            int prime = largestPrimeFactor[x];
            int cnt = 0;    // number of times we can divide x by prime
            while (x % prime == 0) {
                x /= prime;
                cnt++;
            }
            ans *= (cnt+1);
        }
        cout << ans << '\n';
    }
}