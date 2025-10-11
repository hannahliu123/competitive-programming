// USACO 2018 January Contest, Bronze
// Problem 1. Blocked Billboard II

#include <bits/stdc++.h>
using namespace std;

// Start: 4:45
// End: 5:50        1 hour 5 mins

// ARGH I HATE THIS. OMG SO MANY STUPID PROBLEMS I HATE TEST CASE FOUR UGHGGH. Ok
// so I failed ONE singular test case, so i found THREE different ways it could've
// failed and IT TOOK ME SO LONG OMG I SPENT OVER HALF MY TIME FOR ONE STUPID TEST
// CASE AHHAHHAH. Lesson learned. If i pass most test cases, I move on to the next
// problem. Actually no i'll give myself like 15 mins MAX to fix it, then im moving
// on. HUMPH. Alright so what was wrong with my thinking. Oh yeah, so I didn't
// really "think of the right solution". Like i thought if the thing was in cow
// billboard was in the middle, then it counts as u only need one. But that's 
// stupid. If i looked at my solution more carefully i would've realized it. Sigh
// and then i started to rush the implementation :(

// Next time for rectangle geo problems, I can try using a struct so then I can 
// have shorter variable names

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int bl_xl, bl_yl, tr_xl, tr_yl; // lawnmower
    int bl_xc, bl_yc, tr_xc, tr_yc; // cowfeed
    cin >> bl_xl >> bl_yl >> tr_xl >> tr_yl >> bl_xc >> bl_yc >> tr_xc >> tr_yc;

    int area = (tr_xl-bl_xl)*(tr_yl-bl_yl);

    if ((bl_yc<=bl_yl && tr_yc>=tr_yl) || (bl_xc<=bl_xl && tr_xc>=tr_xl)) {
        int w = min(tr_xc, tr_xl)-max(bl_xc, bl_xl);
        int l = min(tr_yc, tr_yl)-max(bl_yc, bl_yl);
        area -= w*l;
        if (bl_xc>bl_xl && tr_xc<tr_xl) {
            area += w*l;
        } else if (bl_yc>bl_yl && tr_yc<tr_yl) {
            area += w*l;
        }
    } else if (bl_yc>=bl_yl && tr_yc<=tr_yl && bl_xc>=bl_xl && tr_xc<=tr_xl) {
        area -= (tr_xc-bl_xc)*(tr_yc-bl_yc);
    } cout << area << endl;
}

// incorect answer 4
