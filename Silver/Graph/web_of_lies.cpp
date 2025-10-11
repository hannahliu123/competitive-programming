// CF - A. Web of Lies - R1400

// Start: 6:02
// End: 6:38        36 mins! HOLY GUACAMOLE MY GOODY GOODNESS HOLY FREAKING COW

// I dunno i felt like i got lucky because the KEY insight that i made that literally 
// determined wether or not i would successfully solve this problem was so unclear and im
// so surprised that i actually got it. Holy moly bro i just had to notice that the number
// of friends with a greated level than each noble determined wether it would end up dying.
// If i hadn't seen that i wouldn't have figured it out. Bruh literally every single cp
// problem is just greedy omg i didn't even end up using graphs lol. kinda curious what the
// editorial says now...

// Um so they talk about stuff liek precomputation and uh edges, but the idea is the same.
// The editorial actually explains what it works though, which is for two main reasons:
// 1. No two nobles will still be friends by the end of the process. This is b/c the weaker
//    one will always keep dying and it's impossible for two to be friends and somehow be
//    connected to lower-leveled yet still alive nobles. The lower-leveled nobles would
//    just keep dying (you can try creating a senario and it will never work out)
// 2. Nobles with friends all weaker than it cannot be killed because once they all die off
//    it'll me only him left and he won't be connected to anything.
// Therefore, if ALL of the noble's friends are weaker than it, then he will survive. I got
// the same thing, but the other way around. I said that if none of the noble's friends are 
// stronger than it, then he will survive. They technically mean the same thing, except the
// editoral's wording is more logical.

// This is just one of those problems where you need to draw a ton of test cases, which I did
// and I chose not to be lazy (about time lol) so it worked out really nicely :D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> greater(N, 0);
    for (int i{0}; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        greater[min(u,v)]++;
    }

    int ans = 0;
    for (int i{0}; i < N; ++i) {
        if (!greater[i]) ans++;      // 1+ greater
    }

    int q;
    cin >> q;
    while (q--) {
        int num;
        cin >> num;

        if (num == 1) { // add a friendship
            int u, v;
            cin >> u >> v;
            u--; v--;
            int lower = min(u,v);
            greater[lower]++;
            if (greater[lower] == 1) ans--; // used to be zero
        } else if (num == 2) {  // remove a friendship
            int u, v;
            cin >> u >> v;
            u--; v--;
            int lower = min(u,v);
            greater[lower]--;
            if (greater[lower] == 0) ans++; // is now zero
        } else {
            cout << ans << endl;
        }
    }
}
