// CF - F. A Bit Odd - R1700

// I came to the realization that if the original inversions of S are odd, obviously
// Alice can just take the whole string. Also i realized you can ignore any 0s that start
// or 1s that end b/c they'll never contribute any inversions. But, if the original inversions
// of S are even, if there are an odd number of used 1s or 0s, we can just take all of them
// along with 1 of the other, which leaves Bob with no valid moves. However, now I came
// across a problem where I didn't know what to do if theres an even number of 1s and 0s. I
// couldn't find under what senarios who would win. when something like this happens, that's
// my sign to step away from this idea and consider something else. 

// What i didn't notice is that in order for alice to win, it is always optimal for her to try
// take all 1s or all 0s. I already noticed that if theres an off number of 1s or 0s to begin
// with then she can obviously do that. But, if there's ever an odd length chain of 1s or 0s,
// then it's also valid because we can take 1 zero after a rightmost odd chain of 1s (so it has
// an off contribution). then for each chain of 1s to the left, if it's odd we can make sure
// an even number of 0s after that is chosen (so that chunk has an even contribution) and is its
// length is even, we dont cant if the number of 0s chosen after is odd or even because its
// contirbution will be even anyways. In this way, all the 1s will be chosen and alice wins!
// Similarly, we can do the same if theres ever an odd length chunk of 0s. 

// Now, how can we prove that Alice always loses if there are no odd length chunks of 1s or 0s?
// Well, in those cases, Alice must chose a subsequence with an odd number of inversions, so
// she can't choose even chains of 1s and 0s or else there would always be an even number of
// inversions. so by chosing odd chunks from a string of all even chunk lenghts, she is creating
// a string with odd chunk lenghts for bob's next move, meaning bob can then win.

// to simplify this all down, the only thing we need to do is check if there's ever an odd chain
// of 1s or 0s (not counding invalid ends). If there is, Alice wins.

// Implementation wise, i started a stupidly overcomplicated way to assess when to skip the
// starting 0s and ending 1s. using a l and r index pointer is so much better lol. anyways, main
// takeaway is that if you can stuck with an idea and dont really know where it's going, try
// something else. these concepts shouldn't be too complicated.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        string s; cin >> s;

        int l=0, r=N-1;
        while (s[l]=='0') l++;
        while (s[r]=='1') r--;

        int ones=0, zeroes=0;
        bool odd = false;
        for (int i=l; i <= r; i++) {
            if (s[i]=='1') {
                if (zeroes%2==1) {
                    odd = true;
                    break;
                } zeroes=0;
                ones++;
            } else {
                if (ones%2==1) {
                    odd = true;
                    break;
                } ones = 0;
                zeroes++;
            }
        } if (zeroes%2==1) odd = true;

        if (odd) cout << "Alice\n";
        else cout << "Bob\n";
    }
}