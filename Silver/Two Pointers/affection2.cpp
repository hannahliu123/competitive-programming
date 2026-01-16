// CF - C. An impassioned circulation of affection - R1600

// Reimplementation :')     10 mins
// okay i still think 2p implementation is tricky b/c u need to make sure u eventually
// break out of the loop and also that l < r. idrk how this solution guarentees that
// and it's sill kinda messy so imma do a 2p implementation deep dive.

// ohh ok so the editorial did it in a way that r tracks the first element not within
// the selected range. so if l=3 and r=10, the range is from [3,9]. This makes it so
// that you don't need the "if (s[0] != c) m--;" check before the loop.
// Another question i had was how you know l will always be less than or equal to r. 
// for this, you know that they both start at 0 and you know that m is greater than 0.
// So as long as the array isn't over, you will always be able to increment r if l=r.
// this is because when l=r you know for sure that m will have at least 1 so r can be
// incremented. this is specific to the problem but usually there's some logic similar
// to this
// last, how are you sure u will eventually break out of the loop? the outermost while
// loop has the condition (l < N && r < N). This means it'll breka if l==N or r==N. we
// know for sure the r will equal N at some point in the code. this is because at some
// point, either r == l == N-1 (last element of string s) or r will reach N before l
// does. but if r == l == N-1 is true, m will be greater than 0 so r will be incremented.
// then l will be incremented. in this senario, both r and l will be equal to N. there
// will never be a senario where l reaches N before r so technically the l < N part is
// unnessecary. 

// yeah there are so many slightly different ways to implement 2p and those slight
// indexing differences make such a huge difference.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    string s;
    cin >> N >> s >> Q;

    while (Q--) {
        int m;
        char c;
        cin >> m >> c;

        int l = 0, r = 0;
        int ans = 0;
        while (r < N) {
            while (r < N) {
                if (s[r] != c && m==0) break;
                else if (s[r] != c) m--;
                r++;
            }
            ans = max(ans, r-l);
            if (s[l++] != c) m++;
        }

        cout << ans << endl;
    }
}
