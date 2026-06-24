// CSES Problem Set - Candy Lottery 
// USACO Guide Expected Values

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;

    vector<double> p(K+1);
    p[0] = 0;
    for (int i=1; i <= K; i++) {
        p[i] = pow((double)i/K, N) - pow((double)(i-1)/K, N);
    }

    double val = 0;
    for (int i=1; i <= K; i++) {
        val += i*p[i];
    }

    cout << fixed << setprecision(6) << val << endl;
}