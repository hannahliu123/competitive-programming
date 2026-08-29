#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> a(N);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    int total = a[N-1];
    int del = 0;
    for (int i=0; i < N-1; i++) {
        total += a[i];
        if (a[i]==a[i+1]) {
            del += 2*a[i];
            total += a[i];
            if (i==N-2) total -= a[N-1];
            i++;
        }
    }
    
    cout << total-del << endl;
}