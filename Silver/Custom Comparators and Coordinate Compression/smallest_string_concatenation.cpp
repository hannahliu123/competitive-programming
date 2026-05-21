// CF - C. The Smallest String Concatenation - R1x00

// Okay at first when i saw this problem i thought it was wayyy too easy bc i 
// thought the bogus solution of jsut sorting it would work. i quickly realized 
// that wasnt the case tho, but it messed with me cos i started an implementation
// too quickly. then i thought i must have to tweak the comparison function 
// somehow, which is true but i didn't rly know how. i ended up settling with an
// idea i thought might possible work where u essentially just compare if a+a < b+b
// except did a ton of unecessary implementation. my idea was that you could either
// have ab or ba in the final string, and if a and b shared some beginning portion
// (say a was longer than b and b was just a prefix of a), then you need to compare
// the ending portion of a with b from the start (ik that makes no sense but wtv).
// However, this is problematic because the two resulting strings can still be diff
// lengths (ex. ab vs abababa) and you can't just keep on adding more of the shorter
// string. plus, my thought process was actually very similar to the real answer and
// i just overcomplicated it.

// The real solution is actually stupidly simple. we know given to strings a and b,
// we want either a+b or b+a (whichever is lexicographically smaller). so, and
// drumroll please...
// the answer is literally a+b < b+a. In other words, if the concatenation of a+b
// is desireable, then we would sort a before b, and if the b+a is more desireable,
// we sort b before a. wow that's literally so direct omg

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    vector<string> a(N);
    for (auto& i : a) cin >> i;

    sort(a.begin(), a.end(), [](auto& x, auto& y){
        return x+y < y+x;
    });
    for (auto& i : a) cout << i;
    cout << endl;
}
