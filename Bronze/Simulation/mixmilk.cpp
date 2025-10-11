// LET ME COOOOOOOOOOOOOK FIRST TRY MUAHAHHAHA EVEN THO IT'S EASY LEVEL

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    int c1, m1, c2, m2, c3, m3;
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

    int x{0};

    for (int i{0}; i < 100; ++i)
    {
        if ((i + 3) % 3 == 0) //0th, 3rd, 6th, ... pour
        {
            x = c2-m2;
            m2 += min(m1, x);
            m1 -= min(m1, x);
        } 
        else if (i % 3 == 1) //1st, 4th, 7th, ... pour
        {
            x = c3-m3;
            m3 += min(m2, x);
            m2 -= min(m2, x);
        } 
        else //2nd, 5th, 8h, ... pour
        {
            x = c1-m1;
            m1 += min(m3, x);
            m3 -= min(m3, x);
        }
    }

    cout << m1 << '\n';
    cout << m2 << '\n';
    cout << m3 << endl;

    return 0;
}
