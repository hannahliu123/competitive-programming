// USACO 2025 US Open Contest, Silver
// Problem 2. Compatible Pairs

// OMG i spent so long trying to figure out what to do if the graph was just a cycle, but
// i never stopped to test if that was even possible. if you test it out, a loop can NEVER
// exist in this senario!! ugh tspmo so much

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B; cin >> N >> A >> B;
    unordered_map<int,vector<int>> cnt{};
    for (int i=0; i < N; i++) {
        int n, id; cin >> n >> id;
        cnt[id].push_back(n);
    }

    unordered_set<int> edge1{};
    unordered_set<int> back{};
    for (auto& id : cnt) {
        int a = A-id.first, b = B-id.first;
        int edges = 0;
        bool itself = false;
        if (cnt.count(a) > 0) {
            if (a==id.first) itself=true;
            edges++;
            id.second.push_back(a);
        } if (a != b && cnt.count(b) > 0) {
            if (b==id.first) itself=true;
            edges++;
            id.second.push_back(b);
        }

        if (edges==1 && itself) back.insert(id.first);
        else if (edges==1 || (edges==2 && itself)) {
            edge1.insert(id.first);
        }
    }

    long long ans = 0;
    auto it = edge1.begin();
    while (edge1.size() > 0) {
        int currId = *it;
        int currCnt = cnt[currId][0];
        int adjId = cnt[currId][1];
        int adjCnt = cnt[adjId][0];
        if (cnt[currId].size() == 3) {
            if (adjId==currId) {
                adjId = cnt[currId][2];
                adjCnt = cnt[adjId][0];
            }
        }
        int prevId = currId;
        edge1.erase(it);

        long long change = min(currCnt, adjCnt);
        ans += change;
        cnt[adjId][0] -= change;
        if (cnt[currId].size() == 3) {
            currCnt -= change;
            ans += (long long)currCnt/2;   // redistribute to itself
        }

        while (cnt[adjId].size() == 3) {
            currCnt = cnt[adjId][0];
            int placeholder = adjId;
            adjId = (cnt[adjId][1]==prevId? cnt[adjId][2] : cnt[adjId][1]);
            prevId = placeholder;
            adjCnt = cnt[adjId][0];
            if (adjId == prevId) {  // redistrubtute to itself
                ans += (long long)currCnt/2;
                break;
            }
            change = min(currCnt, adjCnt);
            ans += change;
            cnt[adjId][0] -= change;
        }

        edge1.erase(adjId);

        it = edge1.begin();
    }

    // get all itself
    for (auto& id : back) {
        ans += (long long)cnt[id][0]/2;
    }

    cout << ans << endl;
}