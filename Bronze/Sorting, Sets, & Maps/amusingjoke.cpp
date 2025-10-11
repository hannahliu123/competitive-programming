// CF

// My only strugle was figuring out how to convert a letter to a number, but I
// just searched it up

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string guest{};
    string host{};
    string letters{};

    cin >> guest >> host >> letters;

    vector<int> original(26);
    vector<int> scrambled(26);

    for (int i{0}; i < guest.size(); ++i) {
        original[guest[i]-'A']++;
    } for (int i{0}; i < host.size(); ++i) {
        original[host[i]-'A']++;
    } for (int i{0}; i < letters.size(); ++i) {
        scrambled[letters[i]-'A']++;
    }

    if (scrambled == original) cout << "YES" << endl;
    else cout << "NO" << endl;
}
