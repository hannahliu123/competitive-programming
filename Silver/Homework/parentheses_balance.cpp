// B - Parentheses Balance

// Start: 11:36
// End: 12:07       31 mins

// super confusing wording so imma just go off guts?
// bruh okay whoever wrote this question sucks. also the cin problem is so freaking
// annoying like wth man. ive never ever had to do that before but ig now ik :/s

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    string trash;
    getline(cin, trash);
    while (N--) {
        string s;
        getline(cin, s);
        vector<char> v{};
        bool pos = true;
        for (auto& i : s) {
            char c = '!';
            if (!v.empty()) c=v.back();
            if (i=='[' || i=='(') v.push_back(i);
            else if (i==']') {
                if (c=='[') v.pop_back();
                else {
                    pos = false;
                    break;
                }
            } else if (i==')') {
                if (c=='(') v.pop_back();
                else {
                    pos = false;
                    break;
                }
            }
        }

        if (v.size()>0) pos = false;
        cout << (pos? "Yes" : "No") << endl;
    }
}

