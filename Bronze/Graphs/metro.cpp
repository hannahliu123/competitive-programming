// CF - 1055A

// Very easy and simple :)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    vector<int> a(n);  // first track, 1 -> n
    vector<int> b(n);  // second track, n -> 1

    for (int i{0}; i < n; ++i) {cin >> a[i];}
    for (int i{0}; i < n; ++i) {cin >> b[i];}

    int pos{0};
    if (a[0] == 1) {
        for (int i{s-1}; i < n; ++i) {
            if (a[i] == 1) {
                if (i == s-1 || (b[i] == 1 && b[s-1] == 1)) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    } cout << "NO" << endl;
    return 0;
}
