// CF - D. Cooperative Game - R2400

// omg bro this is just Floyd's Algorithm WHY is it such a high rating oml

#include <bits/stdc++.h>
using namespace std;

void step1() {
    while (true) {
        bool meet = false;

        cout << "next 0 1\n"; cout.flush();
        int n; string s;
        cin >> n; 
        while (n--) cin >> s;

        cout << "next 1\n"; cout.flush();
        cin >> n;
        while (n--) {
            cin >> s;
            if (s == "01") meet = true;
        }

        if (meet) break;
    }
}

void step2() {
    while (true) {
        bool meet = false;

        cout << "next 0 1 2 3 4 5 6 7 8 9\n"; cout.flush();
        int n; string s;
        cin >> n;
        while (n--) {
            cin >> s;
            if (s == "0123456789") meet = true;
        }

        if (meet) break;
    }
}

int main() {
    step1();    // move friend 0 by 1 and friend 1 by 2 until meet
    step2();    // move all friends by 1 until meet
    cout << "done" << endl;
}
