// D. Array Replacement - R1700

// Start: 9:02-9:27     not any ideas so far    25 mins
// Start: 8:36
// End: 9:10            34 mins

// okay so i have absolutely no idea how this works but i proved it with enough test
// cases that somehow it should? this is one of those problems where i just had to keep
// trying and looking for patterns whilst also using process of elimination to guide my
// endless "trying" of ideas. i have a feeling rearranging math equations would've helped
// here (prolly the intended way to arrive at this solution)

// So, if you try to understand what exactly is happening during each operation, you can
// notice a few things. First, the parities at every index never changes. This means that
// you can know immediately which elements are possible to apply operations to and which
// elements can never change. You can also realize it's desireable to always just stop
// applying operations if it doesn't help/make the current value smaller. But most
// importantly, you should realize that when you apply an operation, you're swapping the
// differences between the left & right elements with the current element. Like if
// a[i]=a[i-1]+2 and a[i+1]=a[i]-4, after the operation, a[i]=a[i-1]-4 and a[i+1]=a[i]+2.
// This is makes sense too because left+right=old+new and you can also prove this pretty
// easily with some math rearrangements. Okay so now this means a ton! Essentially, we
// can just repeatedly apply operations and switch difference values for any item that has
// equal neighbor parities. So, if we find a chunk of elements that can have operations
// applied to it, we can just put the smallest differences first and largest ones last!

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        vector<ll> v(N);
        vector<int> diff{};
        int lastidx = 0;
        v[0] = a[0]; v[N-1] = a[N-1];
        for (int i=1; i < N; i++) {
            diff.push_back(a[i] - a[i-1]);
            if (i==N-1 || abs(a[i-1]%2) != abs(a[i+1]%2)) {
                v[i] = a[i];
                sort(diff.begin(), diff.end());
                int idx=0;
                for (int j=lastidx+1; j < i; j++) {
                    v[j] = (ll)v[lastidx++] + (ll)diff[idx++];
                }
                diff = {};
                lastidx = i;
            }
        }

        for (auto& i : v) cout << i << ' ';
        cout << '\n';
    }
}