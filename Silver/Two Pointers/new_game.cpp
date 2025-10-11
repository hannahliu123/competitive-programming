// CF -  - R1300

// Start: 8:17
// End: 8:58        41 mins

// Brooooo this was so messy. I submitted it wrong FOUR times and fixed something each time...
// yeah that can't be good. And i also had to look at the test cases to see where i messed up
// Okay i corrently did two pointers. I could've used two while loops (doesn't really matter)
// or I could've tracted the distinct numbers by just subtracting right by left but that
// doesn't make too big of a difference. My main mistake was how poorly I structured it. HOLD
// UP! Take back what I said about the for loop being useless. That's actually wayyy better 
// because I can keep incrementing right until I no longer can, then increment left at the
// end of the main while loop. HOLD UP BRO! And then the outer while loop stops when left is
// equal to N (out of bounds) and the inner loop keeps incrementing till right is out of bounds

// Alright so that took me a few tries again... heh. First time I forgot to set right to the 
// max of right and left becase i forgot left could just keep increasing once right reaches a 
// stop. Second I forgot one of the conditions in the inner while loop 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> a(N);
        for (auto& i : a) cin >> i;
        sort(a.begin(), a.end());

        int distinct_nums{1}, cards{1}, ans{0};
        int left{0}, right{0};

        while (left < N) {
            right = max(right, left);
            while (right < N-1 && a[right+1] - a[right] <= 1 && a[right+1] - a[left] < K) {
                right++;
            }
            ans = max(ans, right - left + 1);
            left++;
        }

        // while (left <= right && right < N-1) {
        //     if (distinct_nums < K) {
        //         if (a[right] == a[right + 1]) {
        //             cards++;
        //             right++;
        //         } else if (a[right]+1 == a[right+1]) {
        //             cards++;
        //             right++;
        //             distinct_nums++;
        //         } else {        // new subsection
        //             distinct_nums = 1;
        //             cards = 1;
        //             right++;
        //             left = right;
        //         }
        //     } else if (distinct_nums == K) {
        //         if (a[right] == a[right + 1]) {
        //             cards++;
        //             right++;
        //         } else if (left < right) {
        //             if (a[left]+1 == a[left+1]) distinct_nums--;
        //             left++;
        //             cards--;
        //         } else {        // new subsection
        //             distinct_nums = 1;
        //             cards = 1;
        //             right++;
        //             left = right;
        //         }
        //     }

        //     ans = max(ans, cards);
        // }

        cout << ans << endl;
    }
}
