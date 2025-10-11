// CF - D. Come a Little Closer - R1400

// Start: 1:40
// End: 2:22        42 mins

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second


// don't keep track of indicies - instead directly use the values of each monster.
// This works because all monsters have unique index pairs. So even if they share
// one index (x-value for example), their y-values will be different. So if those
// monsters both had a maximum x-value and one of the monsters were erased, the other
// monster's x-value could be used (as it would be stored in max2). 
// I wouldn't have been able to come up with this logic on my own, as this is the
// first time I've even used structs. At least I understand this implementation now.

struct min_max{
    int min1, min2, max1, max2;

    void fix() {    // ensures min1 is always smaller and max1 is always bigger
        // this way, it is safe to always modify min2/max2 because min1/max1 is "better"
        if (min2 < min1) swap(min1, min2);
        if (max2 > max1) swap(max1, max2);
    }

    min_max (int a, int b) {    // constructer initializing variables
        min1 = max1 = a;        // initialize values with something (placeholder)
        min2 = max2 = b;
        fix();                  // make values correct
    }

    void add(int a) {
        if (a < min2) min2 = a;
        if (a > max2) max2 = a;
        fix();
    }

    long long get_length(int a) {   // the x/y-value of a is to be ignored
        int mx{max1}, mn{min1};
        if (a == max1) mx = max2;   // use the other min/max value
        if (a == min1) mn = min2;
        return mx - mn + 1;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        // stores coordinates of all monsters
        vector<pair<int, int>> monsters(N);
        for (int i{0}; i < N; ++i) {
            cin >> monsters[i].x >> monsters[i].y;
        }

        if (N <= 2) {   // too few items
            cout << N << '\n';
            continue;
        }

        // stores minimum/maximum values for x & y values (set to default for now)
        // keep x and y values separate for organization
        min_max mx(monsters[0].x, monsters[1].x), my(monsters[0].y, monsters[1].y);
        for (int i{2}; i < N; ++i) {    // add all other monsters to min_max
            mx.add(monsters[i].x);
            my.add(monsters[i].y);
        }

        long long ans{1000000000000000000};
        for (int i{0}; i < N; ++i) {    // try moving every single monster
            // ignoring the ONLY monster at index i's x and y values (BIG BRAIN!)
            long long x_len = mx.get_length(monsters[i].x);
            long long y_len = my.get_length(monsters[i].y);
            // check if the box excluding the monster can't even fit the total number of monsters
            // if so, you need to add an extra row or column (whichever results in a smaller area)
            if (x_len * y_len == N-1) ans = min(ans, min((x_len+1)*y_len, x_len*(y_len+1)));
            else ans = min(ans, x_len * y_len);
        }

        cout << ans << '\n';
    }
}
