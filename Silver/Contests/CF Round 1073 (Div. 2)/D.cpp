// D

// oh boy so this problem got complicated really quickly... so i had the right
// idea but i didn't check through all test cases to make sure it worked. i was
// definitely rushing implementation again. so i got to the realization you needed
// to find one index and pick it to be the one that differs but then i tried to
// greedily just select the first possible index, then brute force test if it 
// worked. this won't give the right answer because it's not guarenteed that  
// switching the first bracket guarentees the highest answer. i could've just 
// realized that because we are guarenteed to be given a regular bracket sequence,
// I could've just found the index of the next ( after each ). what no this is
// literally so obvious even if it wasnt a regular sequence because if everything
// before it is the same, we just need that index to differ. then after that you
// need to make sure that the number of ( and ) are the same, which you can do 
// in O(1) time with prefix sums. just find the number of ( before and after as well
// as the number of ) before and after. if ) is less than the prexfix numer of ( + 1, 
/// it's impossible
// another more straightforward way to check if it's impossible is to think of the
// new string being formed as the old one with certian elements deleted. if you want
// to change string s starting from index i, if the next ( bracket is at index j, that
// means all the characters from i-j (including i but not including j) were ). this
// means you must have deleted j-i ) characters. as a result, if you want to be able
// to form a regular bracket sequence, you would need to delete j-i ( characters after
// j. this is only possible if that many exist. i think this is a very clever and way
// more straight-forward way to approach things

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string s;
        cin >> N >> s;

        vector<int> next(N+1, N);     // index of the next (
        vector<int> right_after(N+1, 0);    // # of ( after including the current index
        for (int i{N-1}; i >= 0; --i) {
            if (s[i] == '(') next[i] = i;
            else next[i] = next[i+1];
            if (s[i] == '(') right_after[i]++;
            right_after[i] += right_after[i+1];
        }

        int ans = -1;
        for (int i{0}; i < N; ++i) {
            if (s[i] == ')') {  // try replacing with the next (
                int j = next[i];    // index of next (
                int remove = j-i;   // removed )
                if (j<N-1 && right_after[j+1] >= remove) {
                    ans = max(ans, N-2*remove);
                }
            }
        }

        cout << ans << endl;
    }
}
