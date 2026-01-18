// C

// okay so i really like games problems because there's always like some clicking
// point of realization when you figure out how to beat the game. at the same time
// tho, game problems can get really annoying drawing out test cases and stuff so
// it lowkey kinda depends. for this one, i made a ton of mistakes when doing test
// cases when in reality it's so simple. alice always wins unless she can't make a 
// first move! tbh i think the hardest part of this problem was understanding the
// problem statement lol

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string s;
        cin >> N >> s;

        int z=0;
        for (int i{0}; i < N; ++i) {
            if (s[i]=='0') z++;
        }

        vector<int> ans{};
        for (int i{0}; i < N; ++i) {
            if (i < z && s[i]=='1') ans.push_back(i);
            else if (i >= z && s[i]=='0') ans.push_back(i);
        }

        if (ans.size()==0 || z==0 || z==N) {
            cout << "Bob" << endl;
            continue;
        }

        cout << "Alice\n" << ans.size() << '\n';
        for (auto& i : ans) {
            cout << i+1 << ' ';
        } cout << endl;
    }
}
