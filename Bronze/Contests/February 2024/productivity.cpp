// Problem 3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("productivity.in", "r", stdin);
    //freopen("productivity.out", "w", stdout);

    int N, Q;   // number of farms, queries
    cin >> N >> Q;

    vector<int> closing_time(N);    // c
    vector<int> time(N);            // t
    for (int i{0}; i < N; ++i) {cin >> closing_time[i];}
    for (int i{0}; i < N; ++i) {cin >> time[i];}
    
    int largest_time{0};
    for (int i{0}; i < N; ++i) {
        if (closing_time[i]-time[i]-1 > largest_time) largest_time = closing_time[i]-time[i]-1;
    }
    
    vector<int> max_S(largest_time+1);
    for (int i{0}; i < N; ++i) {
        if (closing_time[i]-time[i]-1>0) max_S[closing_time[i]-time[i]-1]+=1;
    }

    for (int i{0}; i < Q; ++i) {
        int V, S;   // V-how many farms she wants to visit, S-time she wakes up
        cin >> V >> S;

        int count = 0;
        bool boolno = true;
        while (S <= largest_time) {
            if (max_S[S]>0) {
                count += max_S[S];
                if (count >= V) {
                    cout << "YES" << endl;
                    boolno = false;
                    break;
                } 
            } ++S;
        }
        if (boolno) cout << "NO" << endl;
    }
}

// did not pass 2-4 10-17
// timeout 10-17
