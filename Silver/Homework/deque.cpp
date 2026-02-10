// E - Deque-STL

// okay implementation took a while and i knew the solution already so uh idrk. my 
// instinctive idea would just be to track the maximums throughout each subarray and
// deques are the perfect data type for that. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        int l=0;
        deque<int> dq{};
        for (int r{0}; r < N; ++r) {
            while (!dq.empty() && dq.back() < a[r]) dq.pop_back();
            dq.push_back(a[r]);
            if (r+1 >= K) {
                cout << dq.front() << ' ';
                if (dq.front() == a[l]) dq.pop_front();
                l++;
            }
        } cout << endl;
    }
}
