// I watched the solution video, and the reason why I didn't pass the last few 
// test cases was because the number (S) was too large.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i{0}; i < T; ++i) {
        string num;
        cin >> num;

        char last = num[num.length()-1];

        if (last == '0') cout << "E" << '\n';
        else cout << "B" << '\n';
    }
}
