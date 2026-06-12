// CF - C2. Adjust The Presentation (Hard Version) - R1900

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

// holy crap okay so i finally got it and the reason i got wa was because i didn't really
// understand what my code was doing and i was too lazy to actually debug through a test
// case. so apparently for each query, what i was doing was checking the previous member
// that was suppoused to present the slide and the current member that will be presenting
// that slide and then seeing if there were any problems around those two members that were
// either created or fixed by the update. however, if those members are next to eachother
// in a (presentation order), then the problems they fix/create would be double counted
// whereas if they weren't next to eachother, their problems would only be counted once.
// bro tspmo but now im trying to remember what my old code did. imma try reimplementing 
// it that way because i still dont understand why it doesn't work.

#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
vector<set<int>> occ;

int getFirstOcc(int member) {
    if (occ[member].empty()) return M;
    return *occ[member].begin();
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> N >> M >> Q;
        vector<int> a(N); // presenting order
        vector<int> idx(N); // each member's order in a
        for (int i=0; i < N; i++) {
            cin >> a[i]; a[i]--;
            idx[a[i]] = i;
        } vector<int> b(M);
        occ.clear(); occ.resize(N, set<int>{}); // slides each member must present
        for (int i=0; i < M; i++) {
            cin >> b[i]; b[i]--;    // member presenting slide i
            occ[b[i]].insert(i);
        }

        int problems = 0;
        for (int i=0; i < N-1; i++) {
            int firstOcc = getFirstOcc(a[i]);
            int firstOccRight = getFirstOcc(a[i+1]);
            if (firstOcc > firstOccRight) {
                problems += 1;
            }
        }

        if (problems > 0) cout << "TIDAK\n";
        else cout << "YA\n";

        while (Q--) {
            int slide, member; cin >> slide >> member;
            slide--; member--;

            int prevMember = b[slide];
            int prevIdx = idx[prevMember];  // index in a (presenting order)
            int currIdx = idx[member];

            int firstOcc = getFirstOcc(a[prevIdx]); // first occurance of slide's previous member before it's removed from this slide
            if (prevIdx > 0) {
                int firstOccLeft = getFirstOcc(a[prevIdx-1]);
                problems -= firstOcc < firstOccLeft;
            } if (prevIdx < N-1) {
                int firstOccRight = getFirstOcc(a[prevIdx+1]);
                problems -= firstOcc > firstOccRight;
            }

            int currOcc = getFirstOcc(a[currIdx]);  // first occurance of slide's current member before it's assigned to this slide
            if (currIdx > 0) {
                int firstOccLeft = getFirstOcc(a[currIdx-1]);
                if (a[currIdx-1] != prevMember) problems -= currOcc < firstOccLeft;
            } if (currIdx < N-1) {
                int firstOccRight = getFirstOcc(a[currIdx+1]);
                if (a[currIdx+1] != prevMember) problems -= currOcc > firstOccRight;
            }

            // assign this slide to member
            b[slide] = member;
            occ[prevMember].erase(slide);
            occ[member].insert(slide);

            firstOcc = getFirstOcc(a[prevIdx]); // update prevMember's first slide
            if (prevIdx > 0) {
                int firstOccLeft = getFirstOcc(a[prevIdx-1]);
                problems += firstOcc < firstOccLeft;
            } if (prevIdx < N-1) {
                int firstOccRight = getFirstOcc(a[prevIdx+1]);
                problems += firstOcc > firstOccRight;
            } 
            
            currOcc = getFirstOcc(a[currIdx]);  // update currMember's first slide
            if (currIdx > 0) {
                int firstOccLeft = getFirstOcc(a[currIdx-1]);
                if (a[currIdx-1] != prevMember) problems += currOcc < firstOccLeft;
            } if (currIdx < N-1) {
                int firstOccRight = getFirstOcc(a[currIdx+1]);
                if (a[currIdx+1] != prevMember) problems += currOcc > firstOccRight;
            }

            if (problems > 0) cout << "TIDAK\n";
            else cout << "YA\n";
        }
    }
}