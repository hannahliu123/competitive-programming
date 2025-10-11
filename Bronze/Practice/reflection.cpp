// Redo a few weeks after the contest was over (jsut to see if i have another idea)
// USACO 2025 February Contest, Bronze
// Problem 1. Reflection

// Start: 6:23
// End: 7:39    1 hr 16 mins

// Had some implementation issues with the inputting. Another way to have done
// the input is to just have a vector of strings. So for each n, cin the entire
// string. Then when u loop through, u can access those strings with indexing.
// Ohhh and if i wanted to use my vector of vectors, i could've done a for loop
// the resized each vector in the vector. I could've used a for each loop so:

// for (auto& v : canvas) {
//     v.resize(N/2)
// }

// Oh yeah instead of the for loop for U, i could've just done while (U--) like
// i (sometimes) do with t (test cases). That's faster ig but its totally optional.
// Omg also if i kinda like activated two more brain cells i would've simplified
// my stupid equation to find the position lol. If i literally simplified it, then
// i would've gotten N-x-1. Omg im like soooo smart hehe. I could've also seen
// that instead of doing the (? : ) thing, i could've just taken the minimum. Yay
// let me cook! alr well other than that i think my codes finneeee. I'm too lazy 
// to really understand the solution in depth, which is a really bad thing, but
// im like super tired today so imma go do some other stuff (yeah no i should prob
// just sleep) but uh bye bye

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, U;
    cin >> N >> U;

    vector<vector<int>> freq(N/2);
    vector<vector<char>> canvas(N);

    for (int i{0}; i < N; ++i) {
        string temp;
        cin >> temp;
        for (int j{0}; j < N; ++j) {
            char c = temp[j];
            canvas[i].push_back(temp[j]);
            if (i < N/2 && j < N/2) freq[i].push_back(0);
            if (temp[j] == '#') {
                int row = (i<N/2? i : i-(i-N/2)-abs(i-N/2+1));
                int col = (j<N/2? j : j-(j-N/2)-abs(j-N/2+1));
                freq[row][col]++;
            }
        }
    }

    int ans{0};
    for (int i{0}; i < N/2; ++i) {
        for (int j{0}; j < N/2; ++j) {
            if (freq[i][j] == 3 || freq[i][j] == 1) ++ans;
            else if (freq[i][j] == 2) ans += 2;
        }
    } cout << ans << '\n';

    for (int i{0}; i < U; ++i) {
        int r, c;
        cin >> r >> c;
        if (canvas[r-1][c-1] == '#') {  // erase
            canvas[r-1][c-1] = '.';
            r = (r<=N/2? r : r-(r-N/2)-abs(r-N/2-1));
            c = (c<=N/2? c : c-(c-N/2)-abs(c-N/2-1));
            freq[r-1][c-1]--;
            if (freq[r-1][c-1] < 2) --ans;
            else ++ans;
        } else {    // paint
            canvas[r-1][c-1] = '#';
            r = (r<=N/2? r : r-(r-N/2)-abs(r-N/2-1));
            c = (c<=N/2? c : c-(c-N/2)-abs(c-N/2-1));
            freq[r-1][c-1]++;
            if (freq[r-1][c-1] > 2) --ans;
            else ++ans;
        }
        cout << ans << '\n';
    }
}
