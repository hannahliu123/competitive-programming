#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> students(K,0);
    for (int i=0; i < N; i++) {
        int c; cin >> c; c--;
        students[c]++;
    }
    sort(students.begin(), students.end());
    int ans = 0;
    for (int i=K-1; i>=0; i--) {
        if (students[i] >= students[K-1]-1) ans++;
    }

    cout << ans << endl;
}