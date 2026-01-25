// F

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, Ax, Ay, Bx, By;
        cin >> N >> Ax >> Ay >> Bx >> By;

        map<int,vector<int>> coords;
        vector<int> x(N);
        for (auto& i : x) cin >> i;
        vector<int> y(N);
        for (auto& i : y) cin >> i;
        for (int i{0}; i < N; ++i) {
            coords[x[i]].push_back(y[i]);
        }

        long long ans = Bx-Ax;  // horizontal traveling
        // I THINK ITS A GRAPH PROBLEM I JSUT DONT KNOW HOW TO CONSTRUCT
        // THE GRAPH AND IM RUNNING OUT OF TIME AND I KINDA HAVE A GREEDY
        // IDEA BUT IDK IF ITLL WORK :(

        cout << ans << endl;
    }
}
