// CF - Nusret Gökçe

// Start: 10:33
// End: 10:57       24 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> S(N);
    for (auto& s : S) cin >> s;

    for (int i{0}; i < N; ++i) {
        if (i>0 && S[i]+M<S[i-1]) {
            S[i] += (S[i-1]-S[i]-M);
        } if (i<N-1 && S[i]+M<S[i+1]) {
            S[i] += (S[i+1]-S[i]-M);
        }
    }
    
    for (int i{N-1}; i >= 0; --i) {
        if (i>0 && S[i]+M<S[i-1]) {
            S[i] += (S[i-1]-S[i]-M);
        } if (i<N-1 && S[i]+M<S[i+1]) {
            S[i] += (S[i+1]-S[i]-M);
        }
    }

    for (int x : S) cout << x << ' ';
    cout << endl;
}

// WA - Test 3
