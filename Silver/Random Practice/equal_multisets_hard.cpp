// C2. Equal Multisets (Hard Version) - R1800 - 1hr 22 mins

// I got the idea if in the transition, the last and old first are the same then in b they
// have ot be the same two (but not necessarily the same number as a). if they nums are diff
// in a, they have to be identical in b. as long as the first k items follow the rule and 
// end up containing the same items as the first k in a, then if the rest of the array follows
// the rules of same/diff ends, it's possible. wait now i realized this is really similar to
// that one usaco problem. you can just make chains sames and differents across every k 
// items starting from each of the 0->k-1 indexed items. then if there's at least 1 different
// then u know the entire chain. otherwise the whole chain can be anything. then u can just
// see if it's possible for the original k items to be equal to the first k in a.

// um kinda unhappy with how long this took and how badly im implemented the solution. i 
// feel like this really wasn't that hard of a problem but i just overcompliated implementation
// and stuff to the point where i made it super complicated :( the editorials idea is the
// same but the implementation splits each chain into two cases: either everything is the
// same so b[i] can be anything as long as the whole chain is the same, or not everything is
// the same so b[i] must be the first occurance of a[j] such that a[j+K] is different from
// a[j] or a[i] (they're the same). the editorial just tested these two conditions seperately
// whereas i did it all in one loop basically. um i think planning this out before jumping 
// into the code was really important because at first i didn't even realize the chain thing
// and i was trying to implement some really messy idea. idk imo my train of thought was just
// really messy until i got to the chain realization.

// ok key realization is just keep narrowing down the problem to greedy observations if no
// algorithms fit until its as simplified as possible and the implementation isn't a nightmare

#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        bool pos = true;
        vector<int> a(N);
        vector<int> cnta(N+1,0);
        for (int i=0; i < N; i++) {
            cin >> a[i];
            if (i<K) cnta[a[i]]++;
        }
        vector<int> b(N);
        for (int i=0; i < N; i++) {
            cin >> b[i];
        }

        if (!pos) {
            cout << "NO\n"; continue;
        }

        for (int i=0; i < K; i++) {
            for (int j=i+K; j < N; j+=K) {
                if (a[j] != a[j-K]) {
                    if (b[j]==-1) {
                        b[j] = a[j];
                    } else if (b[j] != a[j]) {
                        pos = false; break;
                    }
                    if (b[j-K]==-1) {
                        b[j-K] = a[j-K];
                    } else if (b[j-K] != a[j-K]) {
                        pos = false; break;
                    }
                    if (b[i]==-1) b[i] = a[j-K];
                } else {
                    if (b[j] != -1 && b[j-K] != -1) {
                        if (b[j] != b[j-K]) {
                            pos = false; break;
                        }
                    } else if (b[j] != -1) {
                        b[j-K] = b[j];
                        if (b[i]==-1) b[i] = b[j-K];
                    } else if (b[j-K] != -1) {
                        b[j] = b[j-K];
                    }
                }
            }
            if (b[i] != -1) cnta[b[i]]--;
            if (!pos || (b[i] != -1 && cnta[b[i]] < 0)) {
                pos = false; break;
            }
        }

        cout << (pos? "YES\n" : "NO\n");
    }
}