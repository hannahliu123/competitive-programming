// E

// i knew this was a dp problem and i had an idea of how to solve it, but
// i couldn't figure out how to calculate time complexity to see if my
// solution would even work. i still tried it and it worked, but idrk why.
// So let's examine my solution first before i disect the editorial. i jsut
// precomupted the answer for all values from 1->N. For each number that 
// could be formed, i checked all the larger numbers it could form by 
// multiplying itself with a value smaller than it. At first i chose to
// multiply a value x with all values from sqrt(x) to x (or until it reaches
// N). But then it failed so i tried setting the low to 2 and it worked. i
// only chose sqrt(x) at first because i was looking at perfect squares and
// composite numbers but it lowkey doesn't even work for that i was just 
// guessing. the more important issue is not knowing what the time complexity
// was.

// So the time complexity is O(T*NlogN).  Basically just consider the NlogN
// part because we know N is <= 3*10^5 no matter what. um so i kinda figured
// out some confusing time complexity calculation stuff, but now ik that this
// solution definitely isn't N^2 (but it would've been if i didn't have the
// j*i <= N condition). I technically don't even need the j<=i condition. um
// so if i iterated for every x from 2->x it's essentially N^2 time and i 
// understand that now. If i removed the j<=i condition, each time i loop i
// from 1->N/2, i loop j from 2->N/i. This means the total number of operations
// that these loops perform is N/1-1 + N/2-1 + N/3-1... + N/(N/2)-1 and you can 
// just kinda ignore the -1 (they're only there because we start from 2, not 1).
// and so that pattern of N(1/1 + 1/2 + 1/3 + 1/4... + 1/(N/2)) is something
// known as the harmonic series/progression which has a final value of roughly
// N ln N. Apparently i should just know this bc it's encountered so often uh but
// i could plot it (bounds from x=1 to x=N/2) and plot y=N/x. Then i have to 
// find the area under the curve. wowsers so theres a trick u can use in desmos
// that already calculates that for u but uh its the same as NlnN so yea ig.
// wow that's really complicated but i think i get it. im understanding time 
// complexity more now :)

// ok now FINALLY for the editorial solution, they just looped from 1->N for i
// and then looped j as every multiple of i that was less than N. Even if i 
// wasn't valid, it still processed it but it would've have an effect on teh 
// answer because the default value was very high (1e9). then for each j value
// (multiple of i), it set the ans[j] = max(ans[j], ans[i]+ans[j/i]). its very
// similar to my solution but i used j as the multiple and they used j as the
// product (final value). Their code is a lot cleaner as def easier to identify
// time complexity. i shouldn't try to blindly optimize my code because it makes
// it harder to calculate time complexity and also might not even work properly

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ans(N+1, -1);
        for (int i{0}; i < N; ++i) {
            int x; cin >> x;
            ans[x] = 1;
        }

        for (int i{1}; i <= N/2; ++i) {
            if (ans[i] == -1) continue;
            for (int j{2}; j<=i && j*i <= N; ++j) {
                if (ans[j] == -1) continue;
                if (ans[j*i] == -1) ans[j*i] = ans[i]+ans[j];
                else ans[j*i] = min(ans[j*i], ans[i]+ans[j]);
            }
        }

        for (int i{1}; i <= N; ++i) {
            cout << ans[i] << ' ';
        } cout << endl;
    }
}
