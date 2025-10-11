#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        cout << (n < 6? 15 : (n%2 == 0? n : n+1) * 5 / 2) << '\n';
    }
}
