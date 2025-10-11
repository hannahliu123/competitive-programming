// USACO 2022 December Contest, Silver
// Problem 2. Circular Barn

// girly poop i was right all along. wth man whyd i need to use the freaking seive of 
// eratwhatevertheheck. um im like relaly out of it so imma implement this another day
// and just understand why it works for now

// Quick explanation or clarification for the divide by four thing: whoever lands on/has
// to make their with a multiple of 4 cows remaining will lose. John always makes the
// first move, so all barns staring with multiples of four will result in a loss. Using this
// logic, whenever the barn does NOT start with a multiple of four, John will win because
// he can subtract a number (1, 2, or 3) to guarentee it lands on a multiple of four, or he
// can subtract an even larger number that lands on a multiple of four (optimal for him)

// I figured out the divide by four thing on my own by just drawing test cases and realized
// that all even number cases cost that num/2 "turns" so i figured i just needed to determine
// how many turns odd numbered cases took. I realized i needed to know which numbers were
// odd and i found the seive or eratwhatever online but i thought i was overthinking it. so
// uhhh i guess i wasnt... which is slightly concerning bcos this is a NORMAL leveled problem
// soooo. ugh so now i just need to make that seive thing, and for all prime numbers, the
// number of turns will just be 1. For the other ones (this can also apply for prime numbers
// but itll always be 1 anyways), the winning player (John) will always want to win as 
// quickly as possible, so he would subtract the LARGEST prime number that results in a
// multiple of four (i just added an explanation in the previous paragraph). A rewording of
// that statement would mean that the remainder of the current number divided by four must
// equal the remainder of the chosen number (number of cows to remove) divided by four. This
// would always result in a number divisible by four (common sense you can test it and you'll
// see). This means that we need to keep track of the largest prime number with respective
// remainders of 1, 2, and 3 when divided by four (don't need 0 cos the answer will end up 
// being 1 no matter what duh). I'll keep track of these numbers in the vector "largest_mod"
// The final answer for those odd values is just the starting value - the largest prime
// (which counts as one "turn") plus that resulting value/2 (because it's guarenteed to be
// divisible by four, so in other words even. We already concluded that even numbered barns
// will cost itself/2). 

// Oh and by the way the "largest_mod" vector only needs 1 and 3 b/c we don't need any even
// numbers. This will only be used by odd numbers, but if you wanted to generalize it, it
// still works for all numbers. I feel like only using it for odd ones makes it a lot simpler
// though. For reference, for mod 4 = 0 or 2, the largest prime will ALWAYS be 2 because any
// other even numbers after that woudl be composite (divisible by 2)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    // number of turns before someone wins when both sides play optimally:
    vector<int> turns(5000001, 1);     // 1-indexed
    vector<bool> prime(5000001, true);
    vector<int> largest_mod{2, 1, 2, 3};
    for (int i{2}; i <= 5000000; ++i) {
        if (prime[i]) { // this number is prime
            if ((long long)i * (long long)i <= 5000000) {
                for (int j = i*i; j <= 5000000; j += i) {
                    prime[j] = false;   // composite
                }
            }
            
            // update the largest prime number vector(will only even update for 1 & 3 tho)
            largest_mod[i % 4] = i;
        }
        // update the # of turns before someone wins
        turns[i] = 1 + (i - largest_mod[i % 4])/2;  // technically works for all cases:
        // for even numbers: 1 + (i - 2)/2  which also equals  i/2  b/c  1 = 2/2
        // for prime numbers: 1 + (i - i)/2     which will always equal 1 :)
    }

    while (t--) {
        int N;
        cin >> N;

        int ans = 5000000;
        for (int i{0}; i < N; ++i) {
            int x;  // number of cows in barn i
            cin >> x;
            if (turns[x]/2 < ans/2) ans = turns[x];
        }

        if (ans % 2 == 1) cout << "Farmer John" << endl; // odd number of turns before win
        else cout << "Farmer Nhoj" << endl;
    }
}
