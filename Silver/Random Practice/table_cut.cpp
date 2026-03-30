// CF - D. Table Cut - R1600

// Start: 6:40
// End: 7:28        48 mins

// Omg i spent so long trying to look for some dp solution or prefix sum logic, but in
// reality this was just a greedy problem! omg this problem should've been so simple
// but i overthought it oh welp. the implementation was a BIT tricky tho but im glad
// i figured it out relatively quickly

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;

        vector<vector<int>> table(N, vector<int>(M));
        int ones = 0;
        for (int i=0; i < N; i++) {
            for (int j=0; j < M; j++) {
                cin >> table[i][j];
                if (table[i][j]) ones++;
            }
        }

        int target = ones/2, curr = 0;
        long long ans = (long long)target * (ones-target);
        int endRow = N, endCol = -1;   // last box included (top right)
        if (curr != target) {
            for (int i=N-1; i >= 0; i--) {
                for (int j=0; j < M; j++) {
                    curr += table[i][j];
                    if (curr == target) {
                        endRow = i;
                        endCol = j;
                        break;
                    }
                } if (curr == target) break;
            }
        }
        
        cout << ans << '\n';
        for (int i=0; i < endRow; i++) cout << "D";
        for (int i=0; i <= endCol; i++) cout << "R";
        if (ans > 0) cout << "D";
        for (int i=endCol+1; i < M; i++) cout << "R";
        for (int i=endRow+1; i < N; i++) cout << "D";
        cout << endl;
    }
}
