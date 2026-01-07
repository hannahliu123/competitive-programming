// USACO 2022 December Contest, Silver
// Problem 3. Range Reconstruction

// I spent over an hour and i feel like i got the solution but for some reason it doesnt
// pass test cases 10-14 (half of the test cases omgoaisdjrfliaosjrliasjglkajdgaise). ugh
// idk whats wrong and so imma look at the editorial 

// OH MY FREAKING GOODNESS. I LOVE YOU GEMINI AND I LITERALLY HATE THIS SO MUCH. HOLY
// FREAKING CRAP GUESS WHAT MY MISTAKE WAS. GUESS. I DARE YOU. IF YOU KNOW THEN YOU'RE
// GONNA EXPLODE JUST LIKE I DID JUST NOW. NUH UH ABSOLUTELY NOT NO NO NO NO NO. PERIOD.
// THIS IS NOT REAL OMFG. OKAY ARE YOU READY? DO YOU WANT TO KNOW? YOU DONT WANT TO KNOW.
// I PROMISE YOU DONT HOLY MOLY I FEEL SO AUTISTIC RN CHAT WTH.
// ++j -> --j 
// YEAH THATS RIGHT FEEL MY PAIN OMFG. THAT WAS LITERALLY IT. BRO BE SO FR

// deep breaths. its cos i flipped the loop mid implementation. i also messed up the >= 0
// part by putting <= 0 at first but i caught that one. omg istg this is so annoying bro.
// i wasted SOOOO much time. hey now if this happens during the contest ill be aware of it
// i guess

// ok now that im slightly calmer i do have to note that my implementation was very messy.
// this is a greedy idea because ik an answer exists so there will only be one of two
// options (op1 and op2). i did some messy checking but it worked out. i couldve kept a
// pos boolean and if op1 wasnt possible then i already know op2 is the answer.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> r(N, vector<int>(N));
    for (int i{0}; i < N; ++i) {
        for (int j{i}; j < N; ++j) {
            cin >> r[i][j];   // range from i to j
        }
    }

    vector<pair<int,int>> mn_mx(N);
    vector<int> a(N);
    a[0] = 0; a[1] = r[0][1];
    mn_mx[0] = {a[0],a[1]}; mn_mx[1] = {a[1],a[1]};
    for (int i{2}; i < N; ++i) {    // index of a we want to determine
        int diff = r[i-1][i] - r[i-1][i-1];
        int op1 = a[i-1]+diff, op2 = a[i-1]-diff;
        int mn = op2, mx = op1;
        for (int j{i-2}; j >= 0; --j) {    // for each row going down
            int currmn = mn_mx[j].first;
            int currmx = mn_mx[j].second;
            if (r[j][i] == r[j][i-1]) {
                mn = max(mn, currmn);
                mx = min(mx, currmx);
                if (op1 > mx || op1 < mn) op1 = op2;
                if (op2 > mx || op2 < mn) op2 = op1;
            } else {
                diff = r[j][i] - r[j][i-1];
                int op3 = currmx+diff, op4 = currmn-diff;
                if (op1 != op3 && op1 != op4) op1 = op2;
                if (op2 != op3 && op2 != op4) op2 = op1;
            } if (op1==op2) break;
        }

        a[i] = op1;
        mn_mx[i] = {a[i],a[i]};
        for (int j{0}; j < i; ++j) {    // update mn_mx
            mn_mx[j].first = min(mn_mx[j].first, a[i]);
            mn_mx[j].second = max(mn_mx[j].second, a[i]);
        }
    }

    for (int i{0}; i < N; ++i) {
        cout << a[i];
        if (i != N-1) cout << ' ';
    } cout << endl;
}
