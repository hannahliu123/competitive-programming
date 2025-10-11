// USACO 2021 February Contest, Bronze
// Problem 1. Year of the Cow

// Start: 2:29
// End: 3:07

// I think i planned this one out pretty well. it made sense to my brain so ig that's
// why i was able to solve it relatively easily. Let's go back to graphs... :(

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> years{{"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3}, {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}};
    map<string, pair<int, int>> cows{{"Bessie", {0, 0}}};

    for (int i{0}; i < N; ++i) {
        string cow1, when, year, cow2, x;
        cin >> cow1 >> x >> x >> when >> year >> x >> x >> cow2;

        int c2 = cows[cow2].second;
        int c1 = years[year];
        int c1pos = cows[cow2].first;   // initialize to c2pos
        int diff;
        if (when == "previous") {
            diff = (c2+12 - c1)%12;
            if (diff == 0) diff = 12;
            c1pos -= diff;
        } else {    // when = "next"
            diff = (c1+12 - c2)%12;
            if (diff == 0) diff = 12;
            c1pos += diff;
        } cows.insert({cow1, {c1pos, c1}});
    }

    cout << abs(cows["Elsie"].first) << endl;
}

// incorrect 4, 5, 10

// [cow1] born in [previous/next] [Animal] year from [cow2]
