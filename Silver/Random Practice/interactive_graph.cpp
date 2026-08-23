// C1. Interactive Graph (Simple Version) - R1800

// Okay, here because we are guarenteed that the paths are sorted from least to 
// greatest, this is a key hint that we can binary search on some aspect of the 
// paths. Even better, we're literally told that there are 2^30 possible paths, and
// if we run binary search on that, log_2(2^30) is exactly 30. Then for each iteration
// of the binary search we can have some fat loop to process the path in some way.

// Now we just need to make sure we only ask 32(N+M) questions at the very most. We don't
// know what M is and im assuming the 32 is there beacuse each binary search takes 30
// questions. That means we can run 1 full binary search for each node and 1 for each
// path. Another thing to notice is that all the edges are really just paths of 2 nodes.
// So, we can first run a binary search on the first node u to find out where it starts.
// then we automatically know the next path must contain a path of two nodes (from the
// current node u to its first neighbor v1). Now, for the next path, we can run a binary
// search on the latest path that starts with u -> v1. We know for sure the path after it
// will either be u -> v2 or just the next node after u. This strategy guarentees that we
// only run 1 binary search for finding the starting point of each node and then finding
// the next existing edge, which fits the number of queries we're allowed

// Okay so the biggest thing to realize here was binary search, which i honestly think
// i could've arrived at, then also the order in which we search for things which requires
// only processing the paths with two nodes because those are literlaly all of the edges.
// I think i could've gotten this if i were a bit more locked in. i felt kinda out of it
// this mornign esp cosx i havent done a cf problem in so long. lets try another one

#include <bits/stdc++.h>
using namespace std;

int k;
bool done;
vector<pair<int,int>> ans;

void query() {
    cout << "? " << k << endl;
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    if (n==0) {
        done = true; return;
    } if (n==2) {
        ans.push_back({a[0], a[1]});
        return;
    }
    
    k++;
    query();
}

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;

        ans.clear();
        done = false;
        k = 2;
        query();

        while (!done) {
            int lo = k, hi = 1073741824;
            while (lo < hi) {
                int mid = lo + (hi - lo + 1)/2;
                cout << "? " << mid << endl;
                int n; cin >> n;
                vector<int> a(n);
                for (int i=0; i < n; i++) {
                    cin >> a[i];
                }

                if (n==0 || a[0] > ans.back().first || a[1] > ans.back().second) {
                    hi = mid-1;
                } else if (a[1] == ans.back().second) {
                    lo = mid;
                }
            }

            k = lo + 1;
            query();
        }
        
        cout << "! " << ans.size() << endl;
        for (auto& p : ans) cout << p.first << ' ' << p.second << '\n';
    }
}