// CF - Yet Another Coin Problem - 1934B

// Alright so here we are. What went so completely wrong here. First I completely
// underestimated this problem (when I really have no reason to). This was rated WAY 
// above my level. I kinda just was feeling cocky, saw "brute force", then read the
// problem, and started coding. I didn't analyze time complexity, or think about
// any other types this problem could've been. I didn't try to test my solution before
// I coded, and when i realized it didn't work, i just kept going. I didn't slow down
// and finally start writing on paper. If i learn anything from this, it's that later
// is better than never. Don't just keep going. Bro i had this exact same issue when i
// fenced jolene chan. I felt like i just had to finish the bout. NO!!! Slow down!!!
// Take a breather!!! Goshhh ok. 

// Alright here's the code after reading the first solution. So i was kinda trying
// to find something like this, but erm, as you can see i was not in fact successful.
// How could I have gotten here? well, I had to identify the max possible values of 
// each of the coins. If i had drawn out test cases of multiples of each number very
// cleanly, i would've noticed how each multiple is no longer the best use of one
// number after a certain point (2, 3, 24, and 20) whcih would lead me to this 
// conclusion. I think i just wasn't in the right "concentration" when i tried to
// solve this problem. Imma go to sleep now buh bye

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int ans{1000000000};
        for (int ten{0}; ten <= 2; ++ten) {
            for (int six{0}; six <= 4; ++six) {
                if (10*ten + 6*six <= N) {
                    int n = 10*ten + 6*six;
                    int fif = (N-n)/15;
                    int three = (N-n-(fif*15))/3;
                    int one = N-n-(fif*15)-(three*3);
                    ans = min(ans, fif+ten+six+three+one);
                }                
            }
        }

        cout << ans << '\n';
    }
}
