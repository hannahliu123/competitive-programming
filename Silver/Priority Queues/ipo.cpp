// LC - 502. IPO

// Start: 11:19
// End: 11:37       18 mins

// this terminology is gonna be the end of me lol

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k=2, w=0;
    vector<int> profits{1,2,3};
    vector<int> capital{0,1,1};

    int N = profits.size();
    vector<pair<int,int>> projects(N);
    for (int i=0; i < N; i++) {
        projects[i] = {capital[i], profits[i]};
    } sort(projects.begin(), projects.end());

    int j=0;    // projects idx
    priority_queue<int> net_gain{};    // all possible projects we can select
    for (int i=0; i < k; i++) { // loop thru each possible project we can select
        while (j < N && projects[j].first <= w) {
            // we have enough capital to start these projects
            net_gain.push(projects[j].second);
            j++;
        }

        if (net_gain.empty()) break;

        int highest = net_gain.top();
        net_gain.pop();

        w += highest;
    }

    cout << w << endl;
}
