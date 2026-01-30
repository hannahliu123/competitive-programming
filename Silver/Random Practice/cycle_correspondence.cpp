// USACO 2023 December Contest, Silver
// Problem 2. Cycle Correspondence

// oh boy oh boy oh boy oh boy oh boy. so uh this is a very humbling problem. 
// apparently it's suppoused to be an easy silver problem too and its predicted
// cf rating was like R1300... yet i literlaly got so so so so so stuck on it UGHH.
// this is one of those problems where i feel like the logic is so easy at first
// so i rush to try to implement it and then i realize there are so many edge cases
// that my "easy" implementation doesn't account for. so then i try to find all
// those little edge cases just to finally realize that "easy" solution doesn't 
// work at all once i come across a bigger edge case. bruh tspmo istg i do this
// wayy too often.

// at first i realized this isn't actually a graph problem because the cycle it
// gives you is already in order. and so i thought we could just compare the b
// indexes one by one with the a values to see if they're both there, and if they
// are then that means the cycle can continue. but i didn't realize the most ideal
// path can have like a cc, then a break, then another cc, then a break, etc. and
// i also had some trash impelmentation either way. i should've quickly saw that
// this simple solution wouldn't be correct and the brute force comparing values
// was too non-algorithm-y for this problem.

// basically what really happens is that there is a desired cycle order (which is
// just vector a) and you want vector b to line up with vector a as much as
// possible. the brute force method would of course be to just try starting at
// every single location of K and count how many line up (then add the ones outside)
// and this would solve some of the earlier test cases.

// i think it's very good practice from now on to really just consider the lower
// test cases first. especially if im stuck, it might lead me to another idea. during
// a real contest, tho, i think i should probably move on from this problem if i
// couldn't think of a solution other than my first (simple) idea because it's obv
// too simple.

// but anyways the solution that completes all test cases (which i literally got 
// but it just toko me HOURS and also i forgot to replace an N with K...) is to 
// count the frequency of each shift to acheive a desired sequence. ugh i think my
// main issue with this problem was just wasting so much time. even if i wasted 
// that time i got stuck thinking i had to continue cos i already started. THATS NOT
// GOOD!!! trust from now on i need to be more aware of when a solution will/won't
// work cos usually its obvious but i just ignore it

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(K);
    for (int i{0}; i < K; ++i) {
        cin >> a[i]; a[i]--;
    } vector<int> b(K);
    for (int i{0}; i < K; ++i) {
        cin >> b[i]; b[i]--;
    }

    vector<vector<int>> adj(N);
    adj[a[0]] = {a[1], a[K-1]};
    adj[a[K-1]] = {a[K-2], a[0]};
    for (int i{1}; i < K-1; ++i) {
        adj[a[i]] = {a[i-1], a[i+1]};
    }
    vector<vector<int>> adj2(N);
    adj2[b[0]] = {b[1], b[K-1]};
    adj2[b[K-1]] = {b[K-2], b[0]};
    for (int i{1}; i < K-1; ++i) {
        adj2[b[i]] = {b[i-1], b[i+1]};
    }

    int cc = 0, currcc = 0;
    int startcc = -1;
    int outside = N-K;
    int prev = -1;
    for (auto& i : b) {
        int b1 = adj2[i][0], b2 = adj2[i][1];
        int a1 = -1, a2 = -1;
        if (!adj[i].empty()) {
            a1 = adj[i][0]; a2 = adj[i][1];
            cc = max(cc, 1);    // at least 1 
        } else outside--;

        if (b1==a1 || b1==a2 || b2==a1 || b2==a2) {
            currcc++;
            cc = max(cc, currcc);
            if ((a1 == prev) && ((b1==a1 && b2!=a2) || (b2==a1 && b1!=a2))) {
                if (startcc == -1) startcc = currcc;
                currcc = 0;
            } else if ((a2 == prev) && ((b1==a2 && b2!=a1) || (b2==a2 && b1!=a1))) {
                if (startcc == -1) startcc = currcc;
                currcc = 0;
            }
        } else {
            if (startcc == -1) startcc = currcc;
            currcc = 0;
        } prev = i;
    } cc = max(cc, startcc+currcc);

    cout << cc+outside << endl;
}
