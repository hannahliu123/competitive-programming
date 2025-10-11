// Problem 3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sequences.in", "r", stdin);
    freopen("sequences.out", "w", stdout);

    int T; 
    cin >> T;

    for (int i{0}; i < T; ++i) {
        int N, K;
        cin >> N >> K;

        vector<int> desired(N+1);
        for (int i{0}; i < N; ++i) {cin >> desired[i];}
        desired[N] = 10;

        vector<int> inarow(K);
        vector<int> appearxtimes(K);
        set<int> used{};
        bool works{true};
        for (int i{0}; i < N; i += (inarow[desired[i]-1])) {
            int prev{desired[i]};
            if (!used.count(desired[i])) {
                appearxtimes[desired[i]-1]++;
                for (int j{i}; j < N; ++j) {
                    if (desired[j] == prev) inarow[desired[i]-1]++;
                    else break;
                    prev = desired[j];
                }
            } else {
                int check{0};
                for (int j{i}; j < N+1; ++j) {
                    if (desired[j] == prev) check++;
                    else if (check == inarow[desired[i]-1]) {
                        appearxtimes[desired[i]-1]++;
                        break;
                    }
                    else {
                        cout << "NO" << '\n';
                        works = false;
                        break;
                    }
                    prev = desired[j];
                }
            }
            if (works) used.insert(desired[i]);
            else break;
        }

        if (!works) continue;

        if (K == 1) {
            cout << "YES" << '\n';
            continue;
        } else if (K == 2) {
            if (appearxtimes[0] == appearxtimes[1] || appearxtimes[0] == 0 || appearxtimes[1] == 0) cout << "YES" << '\n';
            else cout << "NO" << '\n';
            continue;
        } else if (K == 3) {
            if ((appearxtimes[0] == appearxtimes[1] && appearxtimes[1] == appearxtimes[2]) || (appearxtimes[0]%2==0 && appearxtimes[1]%2==0) || (appearxtimes[0]%2==0 && appearxtimes[2]%2==0) || (appearxtimes[2]%2==0 && appearxtimes[1]%2==0)) 
                cout << "YES" << '\n';
            else if (appearxtimes[0] == 0) {
                if (appearxtimes[2] == appearxtimes[1]) cout << "YES" << '\n';
            } else if (appearxtimes[1] == 0) {
                if (appearxtimes[2] == appearxtimes[0]) cout << "YES" << '\n';
            } else if (appearxtimes[2] == 0) {
                if (appearxtimes[0] == appearxtimes[1]) cout << "YES" << '\n';
            }
            else cout << "NO" << '\n';
            continue;
        } else if (K == 4) {
            if (appearxtimes[0] == appearxtimes[1] && appearxtimes[1] == appearxtimes[2] && appearxtimes[2] == appearxtimes[3]) cout << "YES" << '\n';
            else {
                int odd{0};
                for (int i{0}; i < 4; ++i) {
                    if (appearxtimes[i]%2 == 1) ++odd;
                    if (appearxtimes[i] == 0) {
                        if (appearxtimes[(i+1)%4] == appearxtimes[(i+2)%4] && appearxtimes[(i+2)%4] == appearxtimes[(i+3)%4]) {
                            cout << "YES" << '\n';
                            works = false;
                            break;
                        }
                    }
                } if(works) {
                    if (odd <= 2) cout << "YES" << '\n';
                    else cout << "NO" << '\n';
                }
            }
        }
    }
}
