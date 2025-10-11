// CF - D. Take a Guess - R1800

// This is just practice implementing it bcos I just learned bitwise stuff
// WHAT THIS WAS SAY WHAT NOW 1800???

#include <bits/stdc++.h>
using namespace std;

int ask(string s, int a, int b) {
    cout << s << ' ' << a << ' ' << b << endl;
    int res;
    cin >> res;
    return res;
}

int sum(int a, int b) {
    int a_and_b = ask("and", a, b);
    int a_or_b = ask("or", a, b);
    int a_xor_b = ~a_and_b & a_or_b;    // xor formula: not a and b (so you're let with 0,0 1,0 or 0,1) AND a or b (1,0 0,1 or 1,1) = only 1,0 or 0,1 :D

    return 2*a_and_b + a_xor_b;     // sum of a+b formula
}

int main() {
    int N, K;
    cin >> N >> K;

    // use bitwise formulas to set up systems of equations to solve for first 2 values
    int a_plus_b = sum(1, 2);
    int a_plus_c = sum(1, 3);
    int b_plus_c = sum(2, 3);

    int a = (a_plus_b + a_plus_c - b_plus_c) / 2;
    int b = a_plus_b - a;
    int c = a_plus_c - a;

    vector<int> ans{a, b, c};
    // now fill out the vector for each other other numbers
    for (int i{4}; i <= N; ++i) {
        ans.push_back(sum(1, i) - a);
    }

    sort(ans.begin(), ans.end());   // sort least -> greatest

    cout << "finish " << ans[K-1];
}
