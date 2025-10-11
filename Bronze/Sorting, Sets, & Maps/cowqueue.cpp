// Level: Normal
// February 2017 Problem 3

// bruh okay this was easy except i couldn't figure out what the syntax error
// thing it kept giving me was. Turns out it was literally the n+1 thing and I
// even noticed it would be a problem when I was typing it but I ignored it and
// said I would come back to it later 💀 let me coooooook

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int N;
    cin >> N;

    vector<pair<int, int>> cows(N);
    for (int i{0}; i < N; ++i) {cin >> cows[i].first >> cows[i].second;}

    sort(cows.begin(), cows.end());

    int time{cows[0].first};
    for (int i{0}; i < N; ++i) {
        time += cows[i].second;
        if (i != N-1) {
            if (cows[i+1].first < time) {cows[i+1].first = time;}
            else time = cows[i+1].first;
        }
    }

    cout << time << endl;
}
