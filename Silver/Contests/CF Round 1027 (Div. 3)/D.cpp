// D - NOTE: LONG LONG!!!!!!!!!!!!!

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        int high1{0}, high2{0}, low1{0}, low2{0};
        // high is small x      low is big x
        int left1{0}, left2{0}, right1{0}, right2{0};
        // left is small y      right is big y

        vector<pair<int, int>> coords{};
        for (int i{0}; i < N; ++i) {
            int x, y;
            cin >> x >> y;
            coords.push_back({--x, --y});       // not sure if value decremented

            if (i > 0) {
                if (x <= coords[high1].first) {
                    high2 = high1;
                    high1 = i;
                } if (x >= coords[low1].first) {
                    low2 = low1;
                    low1 = i;
                } if (y <= coords[left1].second) {
                    left2 = left1;
                    left1 = i;
                } if (y >= coords[right1].second) {
                    right2 = right1;
                    right1 = i;
                }
            }
        }

        if (N == 1 || N == 2) {
            cout << N << '\n';
            continue;
        }

        long long bigxval{coords[low1].first}, smallxval{coords[high1].first};
        long long bigyval{coords[right1].second}, smallyval{coords[left1].second};
        long long ans{(bigxval-smallxval+1)*(bigyval-smallyval+1)};

        // Calculate without low1
        long long x{coords[low2].first-smallxval+1};
        long long y{(low1==right1? coords[right2].second : bigyval)-(low1==left1? coords[left2].second : smallyval)+1};
        long long tryans{(x*y)};
        ans = min(ans, (tryans < N? min(tryans+x, tryans+y) : tryans));
        
        // Calculate without high1
        x = bigxval-coords[high2].first+1;
        y = (high1==right1? coords[right2].second : bigyval)-(high1==left1? coords[left2].second : smallyval)+1;
        tryans = x*y;
        ans = min(ans, (tryans < N? min(tryans+x, tryans+y) : tryans));
        
        // Calculate without right1
        x = (right1==low1? coords[low2].first : bigxval)-(right1==high1? coords[high2].first : smallxval)+1;
        y = coords[right2].first-smallyval+1;
        tryans = x*y;
        ans = min(ans, (tryans < N? min(tryans+x, tryans+y) : tryans));
        
        // Calculate without left1
        x = (left1==low1? coords[low2].first : bigxval)-(left1==high1? coords[high2].first : smallxval)+1;
        y = bigyval-coords[left2].second+1;
        tryans = x*y;
        ans = min(ans, (tryans < N? min(tryans+x, tryans+y) : tryans));
        
        cout << ans << '\n';
    }
}
