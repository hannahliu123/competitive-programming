#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; long long K; cin >> N >> K;
        string s; cin >> s;
        
        long long a=0, b=0;
        for (auto& i : s) {
            if (i=='1') a++;
            else b++;
        }

        K = min(K, min(a,b));
        if (a>=b) {
            a+=K; b-=K;
        } else {
            a-=K; b+=K;
        }
        
        cout << a*(a+1)/2 + b*(b+1)/2 + 1 << '\n';
    }
}