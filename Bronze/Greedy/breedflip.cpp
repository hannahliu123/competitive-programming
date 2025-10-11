#include <bits/stdc++.h>
using namespace std;

// This was so easy. Let's see if there's a more efficent code. Okay so my idea
// was good (greedy), but i didn't HAVE to use a boolean vector. This wouldn't
// really make a difference, but I could've just kept track of if the last index
// I checked had equal breeds using a boolean. If they didn't, then I can ++ans
// then set the boolean to true. I just need to set the boolean back to false 
// if the current index is not equal.

int main()
{
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int N;
    cin >> N;

    string original;
    string current;
    cin >> original >> current;

    vector<bool> needFlip(N);
    for (int i{0}; i < N; ++i) {
        if (original[i] != current[i]) needFlip[i] = true;
    }

    int ans{0};
    if (needFlip[0]) ++ans;
    for (int i{1}; i < N; ++i) {
        if (needFlip[i] && !needFlip[i-1]) ++ans;
    }

    cout << ans << endl;
}
