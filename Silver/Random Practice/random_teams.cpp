// CF - B. Random Teams - R1300

// Start: 3:16
// End: 3:32         16 mins!

#include <bits/stdc++.h>
using namespace std;

long long friends(long long x) {
    return 0.5*(x*x) - 0.5*x;
}

int main() {
    int N, M;   // ppl, teams
    cin >> N >> M;

    // min value
    int norm_size{N/M};
    int big_teams = N%M;
    int normal_teams = M-big_teams;

    long long norm = normal_teams * friends((long long)norm_size);
    long long big = big_teams * friends((long long)(norm_size+1));

    cout << norm + big << ' ' << friends((long long)(N-M+1)) << endl;
}
