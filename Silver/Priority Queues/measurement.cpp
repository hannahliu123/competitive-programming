// USACO 2017 December Contest, Silver
// Problem 2. Milk Measurement

// oh my lordy lordy im actually autistic what the heck was that. bro tspmo
// soooo so soo so much how could it just be a stupid freaking continue im
// gonna crash the heck out oh my lordy lorydydyydy

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int N, G; cin >> N >> G;
    vector<vector<int>> log(N, vector<int>(3));
    set<int> ID;
    for (int i=0; i < N; i++) {
        cin >> log[i][0] >> log[i][1] >> log[i][2];
        ID.insert(log[i][1]);
    }
    sort(log.begin(), log.end());   // sort by entry date
    vector<int> milk(ID.size(), G);     // updated cnt of milk outputs for each cow
    map<int,int> output;  // output -> cnt
    output[G] = 1e9;
    int j=0;
    map<int,int> idx;
    for (auto& id : ID) {
        idx[id] = j++;
    }

    int ans = 0;
    for (int i=0; i < N; i++) { // for each log entry
        int id = idx[log[i][1]];
        int prevMilk = milk[id];    // id's milk before curr update
        int newMilk = prevMilk + log[i][2];
        
        auto it = prev(output.end());
        int mx = (*it).first;   // max milk before curr update
        int cntMx = (*it).second;   // num cows displayed before update

        output[prevMilk]--;
        if (output[prevMilk] == 0) output.erase(prevMilk);
        
        it = prev(output.end());
        int mxWithout = (*it).first;  // max milk output without this cow

        if (prevMilk == mx) {   // cow was a max
            if (newMilk < mx) { // lost output
                if (newMilk > mxWithout) ;  // still max
                else ans++; // mxWithout is the new max
            } else {    // gained output
                if (cntMx == 1) ;   // still the only max
                else ans++; // becomes sole max
            }
        } else {    // cow wasn't a max
            if (newMilk >= mx) ans++;   // ties or greater
        }

        output[newMilk]++;
        milk[id] = newMilk;

        // it = prev(output.end());
        // int newMx = (*it).first;
        // int newCntMx = (*it).second;
        // bool wasMax = (prevMilk == mx);
        // bool isMax = (newMilk == newMx);

        // // 4. Evaluate the transition
        // if (wasMax) {   
        //     // If it was the sole leader, and is still the sole leader, display doesn't change
        //     if (isMax && cntMx == 1 && newCntMx == 1) {
        //         continue; 
        //     }
        //     // Otherwise, since it was a leader and the leader dynamics changed, display changes
        //     ans++; 
        // } else {    
        //     // If it wasn't a leader before, it only changes the display if it becomes a leader now
        //     if (isMax) ans++;   
        // }
    }

    cout << ans << endl;
}
