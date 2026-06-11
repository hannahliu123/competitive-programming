// CF - C2. Adjust The Presentation (Hard Version) - R1x00

// ok so my implementation for this problem got really really messy but the idea is
// there. essentially, for each query, i want to see if the first occurances for each
// of the members in a[i] are increasing in b[i]. so like if you remove all duplicates
// after the first occurance in b, it should be the same as (or a prefix of) a. then
// i needed a way to do this in log N time, so for each update, i kept track of the
// occurance each member has ever had, then i find the first valid occurance that the
// member currently holds. then i see if the member that was replaced and the member
// that was added are both still satisfying their order respective to the members
// around them (left and right). then i keep track of the total problems that mean the
// order is incorrect and update the number of problems.

// also i lowkey just forgot you can use a set to get lowest or highest value so i def
// should've just used a set instead of a priority queue because i can insert and erase
// items

#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
vector<int> a;
vector<int> b;
vector<int> idx;
vector<set<int>> occ;
// vector<pair<bool,bool>> good;

int getFirstOcc(int member) {
    if (occ[member].empty()) return M;
    return *occ[member].begin();
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> N >> M >> Q;
        a.clear(); a.resize(N);
        idx.clear(); idx.resize(N);
        for (int i=0; i < N; i++) {     // order of members
            cin >> a[i]; a[i]--;
            idx[a[i]] = i;
        } b.clear(); b.resize(M);
        occ.clear(); occ.resize(N, set<int>{}); // slides each member must present
        for (int i=0; i < M; i++) {
            cin >> b[i]; b[i]--;    // member presenting slide i
            occ[b[i]].insert(i);
        }

        // good.clear(); good.resize(N, {true,true});
        int problems = 0;
        for (int i=0; i < N-1; i++) {
            int firstOcc = getFirstOcc(a[i]);
            int firstOccRight = getFirstOcc(a[i+1]);
            if (firstOcc > firstOccRight) {
                // good[a[i]].second = false;
                // good[a[i+1]].first = false;
                problems += 1;
            }
        }

        if (problems > 0) cout << "TIDAK\n";
        else cout << "YA\n";

        while (Q--) {
            int slide, member; cin >> slide >> member;
            slide--; member--;

            int prevMember = b[slide];
            int prevIdx = idx[prevMember];
            int currIdx = idx[member];
            int firstOcc = getFirstOcc(a[prevIdx]);
            int currOcc = getFirstOcc(a[currIdx]);

            b[slide] = member;
            occ[prevMember].erase(slide);
            occ[member].insert(slide);

            if (prevIdx > 0) {
                int firstOccLeft = getFirstOcc(a[prevIdx-1]);
                problems -= firstOcc < firstOccLeft;
            } if (prevIdx < N-1) {
                int firstOccRight = getFirstOcc(a[prevIdx+1]);
                problems -= firstOcc > firstOccRight;
            } firstOcc = getFirstOcc(a[prevIdx]);
            if (prevIdx > 0) {
                int firstOccLeft = getFirstOcc(a[prevIdx-1]);
                problems += firstOcc < firstOccLeft;
            } if (prevIdx < N-1) {
                int firstOccRight = getFirstOcc(a[prevIdx+1]);
                problems += firstOcc > firstOccRight;
            } 
            
            if (currIdx > 0) {
                int firstOccLeft = getFirstOcc(a[currIdx-1]);
                problems -= currOcc < firstOccLeft;
            } if (currIdx < N-1) {
                int firstOccRight = getFirstOcc(a[currIdx+1]);
                problems -= currOcc > firstOccRight;
            } currOcc = getFirstOcc(a[currIdx]);
            if (currIdx > 0) {
                int firstOccLeft = getFirstOcc(a[currIdx-1]);
                problems += currOcc < firstOccLeft;
            } if (currIdx < N-1) {
                int firstOccRight = getFirstOcc(a[currIdx+1]);
                problems += currOcc > firstOccRight;
            }

            // // check if the member that got removed creates any problems
            // int firstOcc = getFirstOcc(a[prevIdx]);
            // if (prevIdx > 0) {
            //     int firstOccLeft = getFirstOcc(a[prevIdx-1]);
            //     if (good[a[prevIdx]].first && firstOcc < firstOccLeft) {
            //         // good[a[prevIdx]].first = false;
            //         // good[a[prevIdx-1]].second = false;
            //         problems += 1;
            //     } else if (!good[a[prevIdx]].first && firstOcc > firstOccLeft) {
            //         // good[a[prevIdx]].first = true;
            //         // good[a[prevIdx-1]].second = true;
            //         problems -= 2;
            //     }
            // } if (prevIdx < N-1) {
            //     int firstOccRight = getFirstOcc(a[prevIdx+1]);
            //     if (good[a[prevIdx]].second && firstOcc > firstOccRight) {
            //         // good[a[prevIdx]].second = false;
            //         // good[a[prevIdx+1]].first = false;
            //         problems += 2;
            //     } else if (!good[a[prevIdx]].second && firstOcc < firstOccRight) {
            //         // good[a[prevIdx]].second = true;
            //         // good[a[prevIdx+1]].first = true;
            //         problems -= 2;
            //     } 
            // }

            // // check if the member that got added creates any problems
            // int currOcc = getFirstOcc(a[currIdx]);
            // if (currIdx > 0) {
            //     int firstOccLeft = getFirstOcc(a[currIdx-1]);
            //     if (good[a[currIdx]].first && currOcc < firstOccLeft) {
            //         // good[a[currIdx]].first = false;
            //         // good[a[currIdx-1]].second = false;
            //         problems += 2;
            //     } else if (!good[a[currIdx]].first && currOcc > firstOccLeft) {
            //         // good[a[currIdx]].first = true;
            //         // good[a[currIdx-1]].second = true;
            //         problems -= 2;
            //     }
            // } if (currIdx < N-1) {
            //     int firstOccRight = getFirstOcc(a[currIdx+1]);
            //     if (good[a[currIdx]].second && currOcc > firstOccRight) {
            //         // good[a[currIdx]].second = false;
            //         // good[a[currIdx+1]].first = false;
            //         problems += 2;
            //     } else if (!good[a[currIdx]].second && currOcc < firstOccRight) {
            //         // good[a[currIdx]].second = true;
            //         // good[a[currIdx+1]].first = true;
            //         problems -= 2;
            //     } 
            // }
            
            if (problems > 0) cout << "TIDAK\n";
            else cout << "YA\n";
        }
    }
}