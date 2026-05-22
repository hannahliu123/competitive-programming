// CF - E. William and Robot - R1x00

// ok this was one of those problems where at first i think it's so easy and so
// straightforward, then i quickly realize that solution is bogus and that this
// problem can actually be more complicated than i originally thought. I did make the
// correct realization that for every two cards, William can only have picked half 
// of the cards or less. But the way i implemented it was too "decisive?" and i
// overcomplicated the solution. 

// you know that for every two cards, william can pick 1 at max (unless it's towards
// the end and he has space). so, you can just loop from 1->N and for each pair, have
// william pick the max value. Then, see if william wants to remove one of the cards
// he had picked previously (the minimum value) and select the other card in the pair
// instead. If so, we remove that min value and add that other card. we can literally 
// just simulate this with a priority queue omgmgmmgmg

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> a(N);
    for (auto& i : a) cin >> i;

    priority_queue<int> taken{};
    for (int i=0; i < N; i += 2) {
        taken.push(-1*max(a[i], a[i+1]));
        int mn = -1*taken.top();
        if (min(a[i], a[i+1]) > mn) {
            taken.pop();
            taken.push(-1*min(a[i], a[i+1]));
        }
    }

    long long ans = 0;
    while (!taken.empty()) {
        ans += -1LL * taken.top();
        taken.pop();
    }

    cout << ans << endl;
}
