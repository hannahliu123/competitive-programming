// Problem 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("palindrome.in", "r", stdin);
    //freopen("palindrome.out", "w", stdout);

    int T;
    cin >> T;

    for (int i{0}; i < T; ++i) {
        long long S;
        cin >> S;

        if (S%10==0) {
            cout << 'E' << '\n';
        } else cout << 'B' << '\n';
    }
}

// wrong for 11-13
