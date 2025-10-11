// I just want to see if i remember how to do this permutation stuff

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int total{0};
    vector<string> ans;
    sort(s.begin(), s.end());
    do {
        ++total;
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << total << '\n';

    for (string str : ans) {
        cout << str << '\n';
    }
}
