// USACO 2026 Second Contest, Silver
// Problem 1. Cow-libi 2

// to approach this problem, i needed to realize there are ONLY TWO possible options
// for each cow: john or nhoj, so i can just break these situations up into a few 
// possible options. 
// if a j is next to a j, then they'll both say they are next to a j
// if a n is next to a n, they'll both say theyre next to a j (because they lie)
// if a j is next to a n, the j will say it's next to a n and the n will say its next
// a n (because it lies)
// you will never ever have a case where two cows next to eachother call eachother 
// different names. therefore, for each cow, its left pairing must match another cow's
// right pairing and its right pairing must match another cow's left pairing. this also
// means that the number of N's to the left must match the number of N's to the right
// and the same goes for the number of J's becuase they all have to pair up with someone.
// we can find the order of the cows by following this line of thinking

// also using that thinking u can notice that if you have both NN and JJ, you need at
// least one NJ and one JN (to bring them back together and make sure the lefts and 
// rights can match.

// another important thing to notice is that there MUST be an even number of Ns for the
// claims left and the claims right. the condition above of pairing Ns and Js for left
// and right might work, but we ALSO need to check that there are an even number od Ns
// in left and right. this is becuase every time a cow claims the cow next to it was a N,
// that means it's different from itself. if a J claims it was next to a N, obvioiusly 
// theyre different and if an N claims it was next to a N, they it's lying and they are also
// different. so, bc the cows are in a circle, there can only be a even number of changes
// in N/J because then it wouldn't be valid andd it wouldnt match up.

// using those three points above is enough to pass test cases with C=0 because we dont need
// to construct the final solution. there are two ways tho to construct the final solution but
// imma go over the easier one bc i havent learned eulers path and i dont wanna confuse
// myself. so this is just like a greedy construction. if you know that an answer exists now,
// then you just have to contruct it optimally. start with all of the JJ, then put a JN, then 
// you can put all the NN, then you can put a NJ and keep alternating JN and NJ until you're
// done. this will always work cos you know for sure theres an even number of N's and so there
// will be equal numbers of NJ and JNs (cos only other use for N is NN but it uses both left
// and right sides). 

// omfg bro lesson freaking learned... if something doesnt work and you wanna test possible
// reasons why it didnt work, only change ONE thing at a time... this should be common sense
// but this took me so freaking long because i fixed the issue then changed something that 
// worked into somethign that didnt and i thought i just never did anyting asjlauslriaidsgasdgf
// crashing out. bro usaco doesnt penalize numebr of sumbissions so i can submit it 100 times
// for all they care omfmfmgmfmggg. omg yea my original solution worked im gonan tweak out

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, C;
    cin >> T >> C;
    while (T--) {
        int N; cin >> N;
        vector<vector<int>> combos(4, vector<int>{});    // JJ, JN, NJ, NN
        int lN=0, rN=0;
        vector<char> left(N);
        for (int i{0}; i < N; ++i) {
            cin >> left[i];
            if (left[i]=='N') lN++;
        } vector<char> right(N);
        for (int i{0}; i < N; ++i) {
            cin >> right[i];
            if (right[i]=='N') rN++;

            if (left[i]=='J') {
                if (right[i]=='J') combos[0].push_back(i);
                else combos[1].push_back(i);
            } else {
                if (right[i]=='J') combos[2].push_back(i);
                else combos[3].push_back(i);
            }
        }

        bool check = combos[0].size()>0 && combos[3].size()>0 && combos[1].size()==0;
        if (lN!=rN || lN%2==1 || check) {
            cout << "NO\n";
            continue;
        } else cout << "YES\n";

        if (C==0) continue;

        vector<int> ans{};  // original circular order of cows
        for (auto& i : combos[0]) ans.push_back(i);
        if (combos[1].size() > 0) ans.push_back(combos[1][0]);
        for (auto& i : combos[3]) ans.push_back(i);
        int j = 0;
        for (auto& i : combos[2]) {
            ans.push_back(i);
            if (combos[1].size() > ++j) ans.push_back(combos[1][j]);
        }

        for (int i{0}; i < N; ++i) cout << ans[i]+1 << (i<N-1? " " : "");
        cout << "\nJ";
        char prev = 'J';
        for (int i{0}; i < N-1; ++i) {
            char next = right[ans[i]];
            if (prev == 'J') {
                cout << next;
                prev = next;
            } else {    // prev is N
                if (next == 'N') prev = 'J';
                cout << prev;
            }
        } cout << endl;
    }
}
