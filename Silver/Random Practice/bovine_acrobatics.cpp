// USACO 2023 December Contest, Silver
// Problem 1. Bovine Acrobatics

// NO WAY THIS JUST WORKED YOU HAVE NO IDEA HOW HAPPY I AM RN. BRO I WAS LEGIT
// SITTING THERE ARE PONDERING FOR A POSSIBLE SOLUTION FOR HOUUUUUURS. THIS TOOK 
// LIKE 4 HRS TO FINISH AND I AM SOOOO SO SOOOOO SOOSO OSOOOO HAPPY I WAS ABLE TO
// FIGURE THIS SOLUTION OUT. I MEAN IT WORKED ON FIRST TRY TOO AFTER I SUMBITTED IT
// SO MY LOGIC IS LIKE LOCKED INNN! IM LIKE PRETTY SURE THE EDITORIAL SOLUTION IS
// GONNA BE SIMILAR AS WELL EHEHEHHEEH IM SO HAPPY HAPPY HAAAAAPPY

// I did have to review custom comparators and also basic binary search (so stuff 
// like lower_bound and upper_bound). The implementation was kinda tricky for me
// cos i didn't rly know or understand custom comparators so imma go explore that 
// in depth after i finish reflecting on the problem itself. Getting the idea for
// this solution tho is the main reason why im so proud cos i knew the time 
// complexity kinda revealed it had to be O(N log N) so binary search, but i had
// no idea how. This is a very unique form of binary search and im honestly so
// surprised i even got it.

// Ok wait what the editorial code is completely different. bro. this solution is
// so simple how did i not just realize this broooooo. omg so basically all you need
// to do is keep track of the top layer of cow weights which don't all have to be
// on the same layer. i was calculating layer by layer when in reality I could've 
// just kept a running count as long as they summed up to the number of towers. bro
// this is SOOO simple what the heck. and it also makes sense. yeah and because its
// greedy u always need to put cows on the towers with the largest weight. omg this
// makes me so mad what the heckitydooda. UGHHHH ok imma implement this. wait but 
// also you need a deque for this (which i haven't really used before) so u can
// insert items to the front and also like pop stuff out easily 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;    // distinct weights, towers, K
    cin >> N >> M >> K;

    vector<pair<int,int>> weights(N);   // weight, freq
    for (auto& p : weights) {
        cin >> p.first >> p.second;
        p.second = min(p.second, M);
    }
    sort(weights.rbegin(), weights.rend());     // g -> l

    vector<pair<int,int>> below{{2e9, M}};
    vector<pair<int,int>> next{};
    int used = 0;
    int i = 0;
    long long ans = 0;
    while (i < N) {
        while (used < M && i < N) {
            int min_target = weights[i].first + K;  // upper bound returns first element less than
            pair<int, int> target = {min_target, 0};
            auto comp = [](auto& a, auto& b) {
                return a.first > b.first;
            };
            int index = upper_bound(below.begin(), below.end(), target, comp) - below.begin();
            int possible = 0;
            if (index <= 0) {    // no locations possible so move to next (lower) weight
                i++;
            } else if (index >= below.size()) { // all locations possible
                possible = min(M-used, weights[i].second);
                next.push_back({weights[i].first, possible + used});
                weights[i].second -= possible;
                ans += possible;
                used += possible;
                if (weights[i].second != 0 && used == M) i--;
                i++;
            } else {    // some locations possible
                possible = below[--index].second - used;
                possible = min(possible, weights[i].second);
                next.push_back({weights[i].first, possible + used});
                weights[i].second -= possible;
                ans += possible;
                used += possible;
                if (weights[i].second != 0 && used == M) i--;
                i++;
            }
        }
        used = 0;
        below = next;
        next = {};
    }

    cout << ans << endl;
}
