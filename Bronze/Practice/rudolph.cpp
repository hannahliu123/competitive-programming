// CF - Rudolph and Christmas Tree

// It took a while to find to formula and fix my precision issues

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("rudolph.in", "r", stdin);
    // freopen("rudolph.out", "w", stdout);

    int t; // test cases
    cin >> t;

    for(int i{0}; i < t; ++i) {
        double n, d, h; // num branches, base, height
        cin >> n >> d >> h;

        vector<int> y(n);
        for (int j{0}; j < n; ++j) {cin >> y[j];}
        long double totalArea{n*(d*h/2)};
        long double area{d*h/2};

        for (int j{0}; j < n; ++j) {
            if (j != n-1){
                if (y[j]+h > y[j+1]) {
                    totalArea -= (area*((y[j]+h-y[j+1])*(y[j]+h-y[j+1]))/(h*h)); // (y[j]+h-y[j+1])*d/2*h)*(y[j]+h-y[j+1]
                }
            }
        }
        cout << setprecision(10) << totalArea << '\n';
    }
}
