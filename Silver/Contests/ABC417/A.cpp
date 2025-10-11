#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    string s;
    cin >> N >> A >> B >> s;

    for (int i{0}; i < N; ++i) {
        if (i >= A && i < N-B) cout << s[i];
    }

    cout << endl;
}
