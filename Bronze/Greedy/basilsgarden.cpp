// CF - 1987C, R1200

// I was compeltely stuck until I looked at the first hint. After seeing it, I
// got the solution really quickly. Before seeing the hint, I was too focused
// on drawing test cases and finding patterns. Next time, if i don't make much
// progess after a while of doing that, I want to just stop drawing those cases
// and reread the problem to see if there might be another way for me to solve
// this problem. In this case, the hint that I looked at said, "When will h_n
// first become equal to zero?" This didn't relaly tell me exactly what to do,
// but once I read that, I got the idea of finding the maximum value of seconds
// for each flower, then taking the maximum of those. This would only really
// make logical sense going from right to left, and if i went right to left,
// then the maximum will always be the value at the left-most position (index
// of 0). 

// Okay, so I read the editorial solution, and their code was just slightly
// simpler than mine. We used the same idea, but instead of using a vector
// to constantly keep track of the time used, they used one variable (ans)
// that started with the value of the last flower's height. Then, for each
// flower before that, the ans was changed to the maximum of either ans+1 or
// the height of the current flower.

// Okay, well now the question is, how do i get to the solution without hints?

// So, the simple conclusion is to try drawing test cases first, and if i get
// nowhere, then re read the problem. The question aks for the minimum amount 
// of time before all the flowers have reached a height of zero. Yeah no, I 
// think that if I took a step back and tried simulating what happened in 
// each test case in a different way, then I would've gotten to the answer. I
// need to be more open-minded it my original idea doesn't work.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> h(n);
        for (int i{0}; i < n; ++i) {cin >> h[i];}

        vector<int> ans(n);
        ans[n-1] = h[n-1];
        for (int i{n-2}; i >= 0; --i) {
            if (h[i] > ans[i+1]) ans[i] = h[i];
            else ans[i] = ans[i+1]+1;
        }

        cout << ans[0] << '\n';
    }
}
