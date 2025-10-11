// Level: Hard
// February 2018 Problem 3

// HOLY MOLY I COOKED SO HARD WHATTTT. THAT WAS SO EASY IT ONLY TOOK TWO REALLY
// SHORT TRIES BECAUSE I FIGURED OUT MY MISTAKE SUPER QUICK BAHHHHAHA YESSSS AND I
// PLANNED THIS ONE OUT REALLY WELL TOO YIPPEEEEEE

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int N;  // days since John started logging
    cin >> N;

    vector<int> log(N);
    for (int i{0}; i < N; ++i) {cin >> log[i];} // -1 missing
    log[0] = 0;

    for (int logIndex{0}; logIndex < N; ++logIndex) {
        if (log[logIndex] > 0) {
            int num = log[logIndex];
            for (int i{logIndex-1}; i >= logIndex - log[logIndex]; --i) { 
            // fill slots starting from each positive integer in the log
                if (log[i] == -1) log[i] = --num;
                else if (log[i] != log[i+1]-1){ // invalid log
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    int m{0}; // min
    int M{0}; // max
    for (int i{0}; i < N; ++i) {
        if (log[i] == 0) {
            ++m;
            ++M;
        } else if (log[i] == -1) ++M;
    }

    cout << m << ' ' << M << endl;
}

// 2, 4, 5, 6, 7, 8, 9 incorrect answer
