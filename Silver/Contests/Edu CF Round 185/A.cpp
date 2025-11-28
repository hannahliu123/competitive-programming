// Problem A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        if (N==1) cout << 1 << endl;
        else if (N==2) cout << 9 << endl;
        else if (N < 5) cout << ((N-1)*N)-1 + (N*N)+(N*N)+(N*N)-3 << endl;
        else cout << (N*N-1) + (N-1)*N + ((N-1)*N)-1 + ((N-1)*N)-2 + ((N-2)*N)-1 << endl;
    }
}
