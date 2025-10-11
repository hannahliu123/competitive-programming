#include <bits/stdc++.h>
using namespace std;

// Okay, this one was very very easy and I didn't even have to use an adjacency
// list. I used a normal vector. 

int main() 
{
    int N;
    cin >> N;

    vector<int> f(N+1);
    for (int i{1}; i <= N; ++i) {cin >> f[i];}

    for (int i{1}; i <= N; ++i) {
        if (f[f[f[i]]] == i) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}

// 5 2 4 5 1 3
