// CF - Absolute Sorting
// Start: 8:09

// Erm did not work :'(

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("ab.in", "r", stdin);
    freopen("ab.out", "w", stdout);

    int T;  // test cases
    cin >> T;

    for (int t{0}; t < T; ++t) {
        int N;
        cin >> N;

        vector<int> a(N);
        for (int i{0}; i < N; ++i) {cin >> a[i];}

        int x{0};
        bool works{true};
        for (int i{0}; i < N-1; ++i) {
            int num1 = (a[i]<0? -a[i] : a[i]);
            int num2 = (a[i+1]<0? -a[i+1] : a[i+1]);
            if (num1 > num2) {
                works = false;
                break;
            }
        } if (works) {
            cout << 0 << '\n';
        } else {
            x = a[0];
            works = true;
            for (int i{0}; i < N-1; ++i) {
                int num1 = (a[i]-x<0? -(a[i]-x) : a[i]-x);
                int num2 = (a[i+1]-x<0? -(a[i+1]-x) : a[i+1]-x);
                if (num1 > num2) {
                    works = false;
                    break;
                }
            } if (works) {
                cout << x << '\n';
                continue;
            } else if ((a[0]+a[1])%2 == 0){
                x = (a[0]+a[1])/2;
                works = true;
                for (int i{0}; i < N-1; ++i) {
                    int num1 = (a[i]-x<0? -(a[i]-x) : a[i]-x);
                    int num2 = (a[i+1]-x<0? -(a[i+1]-x) : a[i+1]-x);
                    if (num1 > num2) {
                        works = false;
                        break;
                    }
                } if (works) {
                    cout << x << '\n';
                    continue;
                }
            } cout << -1 << '\n';
        }
    }
}
