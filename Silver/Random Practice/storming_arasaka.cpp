// CF - D. Storming Arasaka - R1500

// alright this solution was pretty straightforward. you just needed find all the 
// factors then notice how and when a factor needed to go on a different layer. 
// also notice that at each layer, we are jsut taking a number from a previous layer
// and multiplying it by a prime. so, layer 0 will always br prime, layer 1 will be
// the product of 2 primes, layer 2 will be the product of 3 primes, and so on. B/c
// each layer has all possible factors that are products of x primes, you can always
// reorder them in a way that two elements next to eachother will have some common
// divisor. Now that we know we need a layer for each product of x primes, we can
// find how many prime makes up N. Add that to the number of primes (individual layers)
// but subtract 1 because one of those primes is used in the construction of N. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        int N2 = N;

        // find all factors in O(sqrtN)
        set<int> f{N};
        vector<pair<int,int>> factors{};
        for (int i=2; i <= (int)sqrt(N); i++) {
            if (N%i==0) {
                bool prime = false;
                while (N2%i==0) {
                    prime = true;
                    N2 /= i;
                } if (prime) factors.push_back({i, 0});
                else f.insert(i);
                if (i!=N/i) f.insert(N/i);
            }
        }

        // for each factor, find its largest factor that's been processed
        int primes = factors.size();
        int ans = 0;
        for (auto& i : f) { // each nonprime factor
            int mx = 0;
            for (auto& j : factors) {
                if (i % j.first == 0) {
                    mx = max(mx, j.second);
                }
            } factors.push_back({i, mx+1});
            ans = max(ans, mx+1);
        }

        cout << primes + ans << endl;
    }
}