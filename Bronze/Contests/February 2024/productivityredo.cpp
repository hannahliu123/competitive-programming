// My attempt at Problem 3 after understanding the solution

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Q;   // number of farms, queries
    cin >> N >> Q;

    vector<int> closing_time(N);    // c
    vector<int> time(N);            // t
    for (int i{0}; i < N; ++i) {cin >> closing_time[i];}
    for (int i{0}; i < N; ++i) {cin >> time[i];}

    // make a vector containing the number of farms you can visit (V) given any
    // wake up time (S) - Two for loops

    vector<int> visit(1000001);
    for (int i{0}; i < N; ++i) {    // for each farm
        int temp{closing_time[i]-time[i]-1};
        if (temp > 0)
            visit[temp]++;
    }

    int highest{0};     // or we could've just done visit[i] = visit[i]+visit[i+1]
    for (int i{1000000}; i > 0; --i) {
        visit[i] += highest;
        if (visit[i] > highest) {
            highest = visit[i];
        }
    }

    for (int i{0}; i < Q; ++i) {        // for each query
        int V, S;
        cin >> V >> S;

        if (visit[S] >= V) cout << "YES" << '\n';
        else  cout << "NO" << '\n';
    }
}
