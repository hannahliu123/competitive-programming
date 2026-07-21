// CF - D. Me When Median Problem - R1700

// brooo okay this was another case of me eliminating binary search too early because
// i keep tyring to binary search ON an answer instead of on X and above or X and below.
// the a_i <= 2*N is a telltale sign that we need to somehow evaluate the individual
// values of all a_i and b_i. once i realized this was a monotonic function such that
// if we can find x or greater as an answer, we can also find x-1 or greater, x-2 or
// greater, and so on. now the problem is reduced to how do we find out if we can acheive
// x or greater or not. Intuitively, you'd want to start by identifying which elements 
// are x or greater. Then, you just want to group elements in a way that in each iteration
// we get rid of as many elements that isn't x or greater as possible. So it's ideal to
// make a group of 4 <x elements so we get rid of two of them. but if that's not possible,
// we can group with >=x elements and get rid of 1 of each. Then it's just a standard
// binary search

// but now to implement this grouping, we need to do it in O(N). Notice though that if we
// start by reducing all the groups of 4 <x elements to 2 <x elements we can get rid of 
// as many as possible. after that, we can only get rid of them along with >=x elements.
// BUT as we keep reducing the array, we might create more groups of 4. because we only 
// want to get rid of the <x elements, it is only desireable for us to create groups of
// 4 which we can do if we have 4 <x or 3 <x elements in a group of 4. this is because 
// in those situations, it is reduced down to 2 <x elements which could potentially make
// another group of 4 <x with its neighbors. the order in which you combine these two types
// of groups doesn't matter being they both lead to 2 a resulting <x elements (which is
// desirable). Thus, we just need to simulating combining as many of those groups as
// possible then compare at the very end if there are more <x or >=x elements

// TWO MAIN TAKEAWAYS:
// 1. binary search omg bro stop thinking its just binary search on ONE value
// 2. try reducing problems to simpler states (in this case 0/1) and see if insights
// from the reduced problem can help you solve the overall probelm

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        vector<int> b(N);
        for (auto& i : b) cin >> i;

        int lo=1, hi=2*N;
        while (lo != hi) {
            int mid = lo + (hi - lo + 1) / 2;
            // see if it's possible to get an answer of mid or higher
            vector<int> a2(N, 0);
            vector<int> b2(N, 0);
            int ones = 0;
            for (int i=0; i < N; i++) {
                if (a[i] >= mid) {
                    a2[i] = 1; ones++;
                } if (b[i] >= mid) {
                    b2[i] = 1; ones++;
                }
            }

            int zeroes = 2*N-ones;
            int prev = a2[0] + b2[0];
            for (int i=1; i < N; i++) {
                int curr = a2[i] + b2[i];
                if (curr + prev == 0) {
                    zeroes -= 2;
                    prev = 0;
                } else if (curr+prev == 1) prev = 0;
                else prev = curr;   // don't combine
            }

            if (ones > zeroes) lo=mid;
            else hi=mid-1;
        }

        cout << lo << endl;
    }
}