// CF - Yet Another Coin Problem - 1934B

// Start: 5:30
// End: 6:20        ugh i gave up

// omg this makes me so mad. this problem brought out like the worst of worst in me.
// I actually hate this so much i never want to see this file again. Im gonna make a
// new one i actually hate this so freaking much omfg

#include <bits/stdc++.h>
using namespace std;

vector<int> coins{15, 10, 6, 3, 1};

int calc(int n, int i) {
    int ans1;
    for (int coin : coins) {
        if (n%coin == 0) {
            ans1 = n/coin;
            break;
        }
    }

    int times = 0, ans = 0;
    for (int coin : coins) {
        if (n >= coin) {
            times = n/coin;
            n -= coin*times;
            ans += times;
            break;
        }
    }

    return ;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

    }
}
