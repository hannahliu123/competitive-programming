// simulating

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> cows{0};
    for (int t{0}; t < 56; ++t) {
        cout << "t = " << t << ":\t| ";
        for (auto& i : cows) {
            if (i<10) cout << i << "  ";
            else cout << i << ' ';
        } cout << endl;

        vector<int> newCows{};
        for (int i{1}; i <= (t+1)/2; ++i) {
            newCows.push_back(cows[i]);
        } newCows.push_back(cows[0]);
        for (int i{(int)newCows.size()}; i < cows.size(); ++i) {
            newCows.push_back(cows[i]);
        } newCows.push_back(t+1);

        cows = newCows;
    }
}
