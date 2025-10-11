// REDO AFTER SEEING SOLUTION

#include <bits/stdc++.h>
using namespace std;

// I need to realize that i can't just skim over stuff when it doesn't make sense. If
// I even read the test case details for like 10 seconds, I would've realized that the
// 2nd test case so annoyingly free, and i could've bs'ed my way through 3 and 4. 

// Ok I read the editorial and i think i understand how they solved it, but let's see
// if i can actually implement it. Basically, I'm just gonna try to create as many
// metal N's as possible, and if I don't have enough materials to make one, then I 
// break. All I have to do is loop through N from N->0, and if i need the metal at
// index i, i will try to get it. If i don't have it and there's no recipe, I break.
// But if there is a recipe, I mark that I need the metal those slots. This solution
// works because it is specified that the recipe for metal i will only contain metals
// with a lower index. We will loop over that loop until it breaks (making a maximum
// of 10^4 units of the final metal). So it'll fit the time complexity. Uhh so if i
// don't currently have a metal I need and there's a recipe, I will add the metal in
// the recipe to the vector of metals that I need, and remove the one i don't have. 
// If I get to the end of the loop and I have everything that I need, then I add 1
// to the final ans and restart the process. ALRIGHT LET'S GET THIS CODED AND SEE IF
// IT WORKS... heh

// Alright so I couldn't figure out what I did wrong that I couldn't pass test cases
// 5 & 7. If i had the patience to draw out a few test cases, I probably would've 
// figured it out, but that would take a long time because I genuinely had no idea
// what I missed. Turns out it was just that if I didn't have enough of a metal, I 
// didn't bother to use up the ones I had (even if it wasn't enough) before I used
// recipes.

// In this problem, I used graphs (adjacency list), simulation, and greedy. I guess
// if I identified this problem as simulation, I could've been able get this idea.
// But it's not just naive simulation, because it's also greedy. I do the best action
// at each stage. This one is kinda hard

// LESSONS: 
//    - If the problem specifies something that is very specific, it must be a big part
//      of the solution (so pay attention to that).
//    - Spend more time thouroughly analyzing the problem. If I treated this as a
//      graph question, then i could've realized I just need to loop backwards because
//      of what I should've noticed in lesson 1

int main() {
    int N;      // ans = max units of metal_N
    cin >> N;

    vector<int> have(N);    // what metals i have
    for (int i{0}; i < N; ++i) cin >> have[i];

    int K;      // recipes
    cin >> K;

    vector<int> make[N];    // how to make each metal
    for (int i{0}; i < K; ++i) {
        int L, M;
        cin >> L >> M;
        --L;
        while (M--) {
            int m;
            cin >> m;
            make[L].push_back(--m);
        }
    }

    int ans{0};
    while (true) {
        vector<int> need(N);
        need[N-1]++;
        bool good = true;
        for (int i{N-1}; i >= 0; --i) {
            if (need[i] > 0) {
                if (have[i] >= need[i]) {
                    have[i] -= need[i];
                } else {
                    if (make[i].size() == 0) {
                        good = false;
                        break;
                    } else {
                        need[i] -= have[i];
                        have[i] = 0;
                        for (int x : make[i]) need[x] += need[i];
                    }
                }
            }
        } if (!good) break;
        ++ans;
    }

    cout << ans << endl;
}

// X - 5, 6, 7
// X - 5, 7
