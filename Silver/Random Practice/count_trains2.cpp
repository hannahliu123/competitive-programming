// CF - G. Count the Trains - R2000 - a few days after reading editorial

// Start: 6:57
// End: 7:56        59 mins!!!

// alright now that i reapproached it without any help, I can start to see why it
// has such a high rating. I still don't think it deserves a 2000, but hey i will
// admit it was quite tricky. First of all i doubt i wouldn've gotten the idea if
// I didn't still remember the implementation a bit. they key is to use a set that
// specifically keeps track of INDEXES of thew new trains. that's pretty unique
// and so it's hard to come up with that idea. one way to get there maybe is to 
// realize that we only need to store the first index that begins each chain. No 
// we NEED to store this information because you need to knwo this in order to 
// determine whether the changed element can break out of the chain. also the problem
// itself is kinda confusing and i didn't even understand it correctly until today.
// After u realize u need to remember the starts of the trains, you need to realize
// this is also a binary search problem so you have to store the indexes. this is
// something i def would not have figured out soooooo im glad i didn't waste too 
// much time just staring at the problem. Even if i did figure all that out tho, i
// would've struggled a ton on implementation. i based my implementation this time
// off the editorial a lot because i still kinda remember it. i got stuck a ton even
// then and had to search up a ton of set syntax (heh!). also the while true loop 
// idea is completely from memory and working with iterators is always confusing. I
// think all of these factors combined with the confusing set of indexes makes it
// really easy to mess up implementation in some tiny unnoticeable area. oh well im
// very glad i tried to redo this problem cos i honestly needed it. i think im gonna
// do this more often :)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        vector<int> a(N);
        set<int> trains{};  // index of the start of each train (l -> g)
        for (int i{0}; i < N; ++i) {
            cin >> a[i];
            int it = *trains.begin();
            if (i==0 || a[i] < a[*trains.rbegin()]) trains.insert(i);
        }
        
        while (M--) {
            int k, d; cin >> k >> d; k--;
            a[k] -= d;
            auto it = trains.upper_bound(k);
            it--;
            if (a[k] < a[*it]) {
                // start a new train
                trains.insert(k);
            }
            while (true) {
                // remove a train
                auto it2 = trains.upper_bound(k);
                if (it2 != trains.end() && a[*it2] >= a[k]) trains.erase(*it2);
                else break;
            }
            cout << trains.size() << ' ';
        } cout << endl;
    }
}
