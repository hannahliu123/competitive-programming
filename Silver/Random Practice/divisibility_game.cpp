// D. Divisibility Game - R1700

// I imlemented a solution that tled in liek 50 mins. i had an idea early on but i just
// dont know how to make it faster. the idea is basically to figure out how many values
// of y are divisible by all numbers, some numbers, or no numbers. the way im doing it
// right now is each unique item in x, i process every item in the range 1 to N+M that is
// a multiple of that x and update its factors to include x. by the end, for every number
// from 1 to N+M, ill have a list of all of its factors. however, in the worst case senario
// where x contains all unique numbers 1 to N, the first x (1) iterates N+M times, then 2
// iterates (N+M)/2 times, then (N+M)/3, all the way until (N+M)/N. this can be rewritten
// as (N+M) * the sum of all 1/i (where i goes from 1 to N+M). Using the logarithmic
// expansion of the Harmonic Series, that equals approximately (N+M)logN.

// wait bruh okay so my solution worked i just needed to change slight time complexity
// hogging areas. like instead of a vector of vectors i could've just had a vector of
// ints. i also needed the unordered set because the duplicates also led to a tle. imo
// thats kinda stupid and this usually doesn't happen but oh wtv

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        unordered_set<int> x{};
        for (int i=0; i < N; i++) {int num; cin >> num; x.insert(num);}
        vector<int> y(M);
        for (int i=0; i < M; i++) cin >> y[i];
        vector<int> divisible(N+M+1,0);
        for (int i : x) {
            for (int j=i; j <= N+M; j += i) {
                divisible[j]++;
            }
        }

        int A=0, B=0, S=0;  // alice, bob, shared
        for (int i=0; i < M; i++) {
            if (divisible[y[i]]==x.size()) A++;
            else if (divisible[y[i]]==0) B++;
            else S++;
        }

        if (A>B) cout << "Alice\n";
        else if (B>A) cout << "Bob\n";
        else if (S%2==1) cout << "Alice\n";
        else cout << "Bob\n";
    }
}