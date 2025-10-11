// CF - B. The Meeting Place Cannot Be Changed - R1600

// Start: 1:51
// End: 2:43            52 mins STUPID DOUBLES OOOOOOMG

#include <bits/stdc++.h>
using namespace std;

int N;
vector<double> pos{};
vector<double> speed{};

bool check(double s) {     // check if friends can meet within s seconds
    long double min_pos{pos[0]-(s*speed[0])};
    long double max_pos{pos[0]+(s*speed[0])};
    if (min_pos < 0) min_pos = 0;
    if (max_pos > 1000000000) max_pos = 1000000000;

    for (int i{1}; i < N; ++i) {
        long double curr_min_pos{pos[i]-(s*speed[i])};
        long double curr_max_pos{pos[i]+(s*speed[i])};
        if (curr_min_pos < 0) curr_min_pos = 0;
        if (curr_max_pos > 1000000000) curr_max_pos = 1000000000;

        if (curr_min_pos > min_pos) min_pos = curr_min_pos;
        if (curr_max_pos < max_pos) max_pos = curr_max_pos;
        if (curr_min_pos > max_pos || curr_max_pos < min_pos) return false;
    }

    return true;
}

int main() {
    cin >> N;
    pos.resize(N);
    speed.resize(N);
    for (auto& i : pos) cin >> i;
    for (auto& i : speed) cin >> i;

    double lo{0};
    double hi{*max_element(pos.begin(), pos.end()) - *min_element(pos.begin(), pos.end())};
    while (hi - lo > 0.0000001) {
        double mid = lo + (hi - lo)/2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }

    cout << fixed <<  hi << endl;
}
