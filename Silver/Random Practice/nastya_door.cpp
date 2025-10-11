// CF - B. Nastya and Door - R1300

// Start: 10:37
// End: 11:14       37 mins

// Bro this shoud NOT have taken so long omg it was a simple two pointers problem

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int N, K;   // mountains, door length
        cin >> N >> K;

        vector<int> a(N);   // mountain heights
        for (auto& i : a) cin >> i;

        vector<bool> peaks(N);    // indexes of all peaks (0-indexed)
        for (int i{1}; i < N-1; ++i) {
            if (a[i] > a[i-1] && a[i] > a[i+1]) peaks[i] = true;
        }

        int l_ans = 1, peaks_cnt_ans = 0;
        int l = 0, r = 1, peaks_cnt = 0;
        while (r < N-1) {
            if (r-l+1 < K) {
                r++;
                if (peaks[r-1]) peaks_cnt++;
            } else if (r-l+1 == K) {
                l++;
                r++;
                if (peaks[l]) peaks_cnt--;
                if (peaks[r-1]) peaks_cnt++;
            } if (peaks_cnt > peaks_cnt_ans) {
                peaks_cnt_ans = peaks_cnt;
                l_ans = l+1;    // 1-indexed
            }
        }

        cout << peaks_cnt_ans+1 << ' ' << l_ans << endl;
    }
}
