#include <bits/stdc++.h>
using namespace std;

int main() {
    double val = 0.44222222222222222222222;
    cout << int(val * 100) << '\n';
    cout << fixed << setprecision(1) << val << endl;
    double rounded = round(val*100 + 1e-9)/100;
    cout << val+1e-9 << endl;

    string line;
    string last;
    while (getline(cin, line)) {
        cout << line << " END OF LINE\n";
        last = line;
    }
    cout << "EXECUTED";
    stringstream ss(last);
    string curr;
    while (ss >> curr) {
        cout << curr << "SS ";
    } return 0;
}
