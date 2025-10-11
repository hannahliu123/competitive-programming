// PAPS 9.3 - Multidimensional DP - Ferry Loading

#include <bits/stdc++.h>
using namespace std;

// A ferry is to be loaded with cars of different lengths, with a long line of
// cars currently queued up for a place. The ferry consists of four lanes, each
// of the same length. When the next car in the line enters the ferry, it picks
// one of the lanes and parks behind the last car in that line. There must be
// safety margin of 1 meter between any two parked cars.
// Given the length of the ferry and the length of the cars in the queue,
// compute the maximal amount of cars that can park if they choose the lanes
// optimally.

int N, L;   // number of cars and length of ferry
vector<int> cars;   // lengths of each car
map<tuple<int, int, int, int, int>, int> solved{};      // memoization

int solve(int pos, int a, int b, int c, int d) {
    int len = cars[pos]+1;

    if (pos == N) return 0;     // surpassed available positions

    // For memoization:
    auto state = make_tuple(pos, a, b, c, d);
    if (solved.count(state)) return solved[state];
    
    // If not aleady calculated, calculate it, but only if the car fits:
    int maxcars{0};
    if (a >= len) {
        maxcars = max(maxcars, solve(pos+1, a-(len), b, c, d)+1);
    }
    if (b >= len) {
        maxcars = max(maxcars, solve(pos+1, a, b-(len), c, d)+1);
    }
    if (c >= len) {
        maxcars = max(maxcars, solve(pos+1, a, b, c-(len), d)+1);
    }
    if (d >= len) {
        maxcars = max(maxcars, solve(pos+1, a, b, c, d-(len))+1);
    }

    solved[state] = maxcars;
    return maxcars;
}

int main() {
    cin >> N >> L;
    cars.resize(N);
    for (auto& c: cars){cin >> c;}

    // start at position of the 0th car with empty lanes (full space available)
    // add one because the last car technically takes up extra spacing?
    cout << solve(0, L+1, L+1, L+1, L+1) << endl;
}
