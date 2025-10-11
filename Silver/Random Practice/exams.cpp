// CF - C. Exams - R1400

// Start: 10:54
// End: 11:03       9 mins...

// What in the worlds... how was a R1400 this simple...? umm ego boost or what??? HELLO?

// Oh okay maybe it's cos this was uh... ELEVEN years ago. Yeah no 1400 cannot be this easy

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> dates(N);
    for (int i{0}; i < N; ++i) {
        cin >> dates[i].first >> dates[i].second;
    }

    sort(dates.begin(), dates.end());   // least -> greatest

    int curr_day = dates[0].second;
    for (int i{1}; i < N; ++i) {
        if (dates[i].second >= curr_day) {
            curr_day = dates[i].second;
        } else {
            curr_day = dates[i].first;
        }
    }

    cout << curr_day << endl;
}
