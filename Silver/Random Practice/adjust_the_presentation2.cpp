// OH MY LORDY LORDY I DID IT. HOLY CRAP I FIGURED IT OUT. SO MY OLD SOLUTION DID WORK
// ALL ALONG I FEEL UGHHH SO SDJFALIDSFJLRKJSDFLAJ OMG ITS SUCH A MINOR FREAKING ISSUE
// IM CRASHING OUT RN IF YOU COULDN'T TELL OML OML OML.

// okay so the issue was i forgot if the member isn't in the array b, we set their 
// first occurance equal to M. no. i didn't even forget about this. I literally KNEW
// i might have a problem with this later on but i didnt think too much abt it and
// then i kinda forgot about it and UGHHHH but at least now i know 😢

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
        vector<pair<bool,bool>> good(N, {true,true});
        for (int i=0; i < N-1; i++) {
            int firstOcc = getFirstOcc(a[i]);
            int firstOccRight = getFirstOcc(a[i+1]);
            if (firstOcc > firstOccRight) {
                good[a[i]].second = false;
                good[a[i+1]].first = false;
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
            b[slide] = member;
            occ[prevMember].erase(slide);
            occ[member].insert(slide);

            // check if the member that got removed creates any problems
            int firstOcc = getFirstOcc(a[prevIdx]); // first occurance of slide's previous member before it's removed from this slide
            if (prevIdx > 0) {
                int firstOccLeft = getFirstOcc(a[prevIdx-1]);
                if (good[a[prevIdx]].first && firstOcc < firstOccLeft) {
                    // relationship was good but now it's not
                    good[a[prevIdx]].first = false;
                    good[a[prevIdx-1]].second = false;
                    problems++;
                } else if (!good[a[prevIdx]].first && firstOcc >= firstOccLeft) {
                    // relationship was bad but now it's good
                    good[a[prevIdx]].first = true;
                    good[a[prevIdx-1]].second = true;
                    problems--;
                }
            } if (prevIdx < N-1) {
                int firstOccRight = getFirstOcc(a[prevIdx+1]);
                if (good[a[prevIdx]].second && firstOcc > firstOccRight) {
                    good[a[prevIdx]].second = false;
                    good[a[prevIdx+1]].first = false;
                    problems++;
                } else if (!good[a[prevIdx]].second && firstOcc <= firstOccRight) {
                    good[a[prevIdx]].second = true;
                    good[a[prevIdx+1]].first = true;
                    problems--;
                } 
            }
            
            int currOcc = getFirstOcc(a[currIdx]);  // first occurance of slide's current member before it's assigned to this slide
            if (currIdx > 0) {
                int firstOccLeft = getFirstOcc(a[currIdx-1]);
                if (good[a[currIdx]].first && currOcc < firstOccLeft) {
                    good[a[currIdx]].first = false;
                    good[a[currIdx-1]].second = false;
                    problems++;
                } else if (!good[a[currIdx]].first && currOcc >= firstOccLeft) {
                    good[a[currIdx]].first = true;
                    good[a[currIdx-1]].second = true;
                    problems--;
                }
            } if (currIdx < N-1) {
                int firstOccRight = getFirstOcc(a[currIdx+1]);
                if (good[a[currIdx]].second && currOcc > firstOccRight) {
                    good[a[currIdx]].second = false;
                    good[a[currIdx+1]].first = false;
                    problems++;
                } else if (!good[a[currIdx]].second && currOcc <= firstOccRight) {
                    good[a[currIdx]].second = true;
                    good[a[currIdx+1]].first = true;
                    problems--;
                } 
            }

            if (problems > 0) cout << "TIDAK\n";
            else cout << "YA\n";
        }
    }
}