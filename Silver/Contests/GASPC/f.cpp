#include <bits/stdc++.h>
using namespace std;

int main() {
    int dollars, cents;
    char dot;
    cin >> dollars >> dot >> cents;

    vector<int> money(6, 0);
    money[0] = dollars;

    if (cents-50 >= 0) {
        cents -= 50;
        money[1] = 1;
    } if (cents-25 >= 0) {
        cents -= 25;
        money[2] = 1;
    } while (cents-10 >= 0) {
        cents -= 10;
        money[3]++;
    } if (cents-5 >= 0) {
        cents -= 5;
        money[4]++;
    } while (cents-1 >= 0) {
        cents -= 1;
        money[5]++;
    }

    for (int i{0}; i < 6; ++i) {
        cout << money[i];
        if (i<5) cout << ",";
    }

    return 0;
}
