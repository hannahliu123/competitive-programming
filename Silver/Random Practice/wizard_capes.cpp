// CF - C. The Ancient Wizards' Capes - R1500

// So the key idea here is that a. there is a max of 2 possible solutions, and b. you can 
// break all individual a values into 1 of 4 scenarios. With each given numbers, you can 
// immediately determine the side the wizards hold their capes if they are different. But,
// if they are the same it gets more tricky. In order to actually solve it, just keep two
// different possibilities for cape combos (op1 and op2 in my code) and at the end test to
// see if they work. I was just missing that key insight of comparing wizards left to right
// and also the idea for keeping two different options (and yea its like really important
// so idk if i wouldve been able to solve this. i looked at the editorial btw but not the
// implementation (cos it's in python anyways)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<int> a(N);
        for (auto& i : a) cin >> i;

        vector<bool> op1(N, false); // 0 (false) = left     1 (true) = right
        vector<bool> op2(N, false); // 0 (false) = left     1 (true) = right
        op2[0] = true;
        for (int i{1}; i < N; ++i) {
            if (a[i-1] > a[i]) {        // op[i-1] should be true
                op1[i] = true;
                op2[i] = true;
            } else if (a[i-1] < a[i]) { // op[i-1] should be false
                op1[i] = false;
                op2[i] = false;
            } else if (a[i-1] == a[i]) {
                if (op1[i-1]) op1[i] = false;
                else if (!op1[i-1]) op1[i] = true;
                if (op2[i-1]) op2[i] = false;
                else if (!op2[i-1]) op2[i] = true;
            }
        }

        // See if they work
        int total1 = accumulate(op1.begin(), op1.end(), 1); // bc op1[0] = false
        int total2 = accumulate(op2.begin(), op2.end(), 0);
        bool first = true;
        bool second = true;
        for (int i{0}; i < N; ++i) {
            if (total1 != a[i]) first = false;
            if (total2 != a[i]) second = false;

            if (i == N-1) break;
            if (op1[i] && op1[i+1]) total1--;   // right
            if (!op1[i] && !op1[i+1]) total1++;  // left
            if (op2[i] && op2[i+1]) total2--;   // right
            if (!op2[i] && !op2[i+1]) total2++;  // left
        }

        cout << first+second << endl;
    }
}
