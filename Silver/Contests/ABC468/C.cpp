// C

// for this problem u can actually directly compare vectors lexicographically using the
// > or < operators. so i didnt need to make it into a string. i also just needed to know
// how to use next_permutation. then generating all permutations takes O(N!)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string P="", Q="";
    for (int i=1; i <= N; i++) {
        int x; cin >> x;
        P += x+'0';
    }
    for (int i=1; i <= N; i++) {
        int x; cin >> x;
        Q += x+'0';
    }

    string nums="";
    for (int i=1; i <= N; i++) nums += i+'0';

    int cnt = 0;
    do {
        if (nums > P && nums < Q) cnt++;
    } while (next_permutation(nums.begin(), nums.end()));

    cout << cnt << '\n';
}