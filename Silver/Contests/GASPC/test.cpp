#include <bits/stdc++.h>
using namespace std;

int main() {
    // double val = 0.44222222222222222222222;
    // cout << int(val * 100) << '\n';
    // cout << fixed << setprecision(1) << val << endl;
    // double rounded = round(val*100 + 1e-9)/100;
    // cout << val+1e-9 << endl;

    // string line;
    // string last;
    // while (getline(cin, line)) {
    //     cout << line << " END OF LINE\n";
    //     last = line;
    // }
    // cout << "EXECUTED";
    // stringstream ss(last);
    // string curr;
    // while (ss >> curr) {
    //     cout << curr << "SS ";
    // } return 0;

    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    vector<int> v1{};
    int x;
    stringstream ss1(line1);
    while (ss1 >> x) v1.push_back(x);
    vector<int> v2{};
    stringstream ss2(line2);
    while (ss2 >> x) v2.push_back(x);

    cout << "vector 1: ";
    for (auto& i : v1) cout << i << ' ';
    cout << "\nvector 2: ";
    for (auto& i : v2) cout << i << ' ';
}
