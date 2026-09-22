// this problem took me an hour to solve and i liek BARELY figured it out. i had to
// play around with so many different representations of the problem until i found
// something that worked. At first, i didn't really know how to even solve the 
// problem by hand, which means there probably isn't a greedy algorithm. also the
// problem doesn't require you simulate the moving of roads, you just have to find
// the max answer. So, i realized that when you shift sections of a road, you're
// increasing the height of the non-rightmost sections and shifting them right by 1
// then decreasing the height of the rightmost section and shifting it left by
// however much its height decreased by. Using this, you can basically represent this
// problem as shifting left and decreasing height by 1 or shifting right and increasing
// height by 1. This essentailly rewording the problem in terms of math and numbers.

// The key invariant is that height-position (a_i - i) never changes, and we can
// move all sections around in whatever order we please. Why? well, starting with
// some roads heights in the order A B C D E, we can rearrange those heights in any
// order by just repeatedly moving the desired leftmost element to the front

// Now knowing this, we can try fixing the final height of the connected road by
// shifting as many road segments as possible to that height then seeing how many are
// connected. If k is the fixed height and j is the next index of the elemnent, we
// want k-j = a_i-i, so for all elements, j = k-a_i+i. Notice that k will always be
// a constant, so if we increase k by say 5, every singly element will have the j index
// shifted up by 5. So, we can just remove k and isntead find the maximum consecutive
// sequence of j indexes where j = i-a_i

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        vector<int> v{};
        for (int i=0; i < N; i++) {
            v.push_back(i-a[i]);
        } sort(v.begin(), v.end());

        int ans = 1;
        int chain = 1;
        for (int i=1; i<N; i++) {
            if (v[i]==v[i-1]) continue;
            if (v[i]==v[i-1]+1) {
                chain++;
            } else {
                ans = max(ans, chain);
                chain = 1;
            }
        }

        cout << max(ans, chain) << '\n';
    }
}