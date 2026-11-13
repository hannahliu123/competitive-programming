// using better i/o would've made this easier

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    if (s.length() < 3 || s.length() > 1000) {
        cout << "Invalid Input.";
        return 0;
    }

    for (int i{0}; i < s.length(); ++i) {
        if (s[i] =='!' || s[i]=='.' || s[i]==',' || s[i]=='-') s[i] = ' ';
    } s += ' ';

    stringstream ss(s);
    string curr;
    vector<string> pals{};
    while (ss >> curr) {
        string lower = "";
        for (auto& c : curr) lower += tolower(c);
        string rev = lower;
        reverse(rev.begin(), rev.end());
        if (lower==rev && curr.length()>1) {
            pals.push_back(curr);
        }
    }

    if (pals.size() > 0) {
        cout << pals.size();
        for (auto& s : pals) {
            cout << "," << s;
        }
    } else cout << "Bonus points needed.";

    return 0;
}
