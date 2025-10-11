// Problem 3

// I DON'T KNOW WHAT I DID, BUT IT WORKED!!! I'LL TAKE IT BRO! 3:24

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("mooloo.in", "r", stdin);
    //freopen("mooloo.out", "w", stdout);

    int N;
    long long K;
    cin >> N >> K;

    vector<long long> days(N);
    for (int i{0}; i < N; ++i) {cin >> days[i];}

    long long moonies{K+1};  // total cost
    long long compare{days[0]};
    long long prevcost{1+K};
    for (int i{0}; i < N-1; ++i) {
        long long cost{0};
        int test1 = prevcost+1+K;
        int test2 = K+(days[i+1]-compare+1);
        cost = min(prevcost+1+K, (K+(days[i+1]-compare+1)));
        if ((K+(days[i+1]-compare+1)) >= prevcost+1+K) {    // new subscription
            compare = days[i+1];
            moonies += K+1;
            prevcost = K+1;
        } else {
            moonies += (days[i+1]-days[i]);
            prevcost = cost;
        }
    }

    cout << moonies << endl;
}

// only passed test cases 1 and 2
// passed 1, 2, 4, 5
