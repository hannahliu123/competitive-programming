// CF - F. Fragmented Nim - R1600

// Start: 7:02
// End: 7:36        34 mins

// I wasn't really confident that this would work but hey it did. this is just a greedy
// problem so all i did was draw test cases and look for a pattern. implementation was
// super easy too. im not actually completely sure why this works so lemme read the 
// editorial.

// ok yeah so if there are multiple stones you never wanna chose that pile for your
// opponent because they can either take all or take all but one and make you take that
// last one. your opponent can chose whichever is more desireable for themselves so you
// always want to chose up all the piles with one stone for your opponent. therefore the
// solution is based entirely on how many piles of 1 there are. obviously if there are
// only twos then alice controls the whole game. if there are only ones the answer is
// obvious as well. for other cases if there are an odd number of piles of one then 
// bob wins because they will alternate picking those piles A, B, A... which always end
// on Alice picking the last pile of one. then Bob will be in control. vice versa for 
// Alice if there are an even number of ones

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        int ones = 0, twos = 0;
        for (int i{0}; i < N; ++i) {
            int x; cin >> x;
            if (x==1) ones++;
            else twos++;
        }

        if (twos == 0) cout << (N%2==0? "Bob" : "Alice") << endl;
        else if (ones % 2 == 0) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
}
