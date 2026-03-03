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

    int cnt = 0;
    string curr = "";
    vector<string> pals{};
    for (int i{0}; i < s.length(); ++i) {
        if (s[i]=='!' || s[i]=='.' || s[i]==' ' || s[i]==',' || s[i]=='-' || i==s.length()-1) {
            bool pal = true;
            int k = curr.length()-1;
            for (int j{0}; j < curr.length()/2; ++j) {
                int a = curr[j], b = curr[k];
                if (a!=b && (a+32)!=b) {
                    pal = false;
                    break;
                } k--;
            } 
            if (pal && curr.length()>1) {
                cnt++;
                pals.push_back(curr);
            } curr = "";
        } else {
            curr += s[i];
        }
    }

    if (cnt > 0) {
        cout << cnt;
        for (auto& s : pals) {
            cout << "," << s;
        }
    } else cout << "Bonus points needed.";

    return 0;
}
