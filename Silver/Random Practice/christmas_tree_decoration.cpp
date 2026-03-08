// CF - D. Christmas Tree Decoration - R1600

// okay i finally figured this one out with pascals thingymabob and imma write this
// number theory stuff in my notes not here 

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int t; cin >> t;

    vector<int> f(51, 1);   // factorials from 0->50 (after mod)
    for (int i{1}; i < 51; ++i) {
        f[i] = (f[i-1] * (long long)i) % MOD;
    }

    // nCr = (n-1)C(r-1) + (n-1)Cr
    vector<vector<long long>> C(51, vector<long long>(51, 0));    // C[i][j] = nCr(i,j)
    for (int i{0}; i < 51; ++i) {
        for (int j{0}; j <= i; ++j) {
            if (j==0) C[i][j] = 1;
            else C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    while (t--) {
        int N; cin >> N;
        int total = 0;
        vector<int> a(N+1);
        for (auto& i : a) {
            cin >> i;
            total += i;
        }

        int norm = total/N; // min number of decorations a person must hang
        int more = total%N; // number of people hanging an extra decoration
        int mxCnt = 0;  // number of people who must hang an extra decoration
        bool pos = true;
        for (int i{1}; i <= N; ++i) {
            if (a[i] > norm+1) {
                pos = false;
                break;
            } if (a[i] == norm+1) {
                mxCnt++;
            }
        }

        if (!pos || mxCnt > more) {
            cout << 0 << '\n';
            continue;
        }

        int extra = more-mxCnt; // # of people who need to hang an extra decoration (not guarenteed in mxCnt)
        int ops = N-mxCnt; // # of options for people who can be in more
        int normCnt = N-more;

        // nCr(ops, extra) - we have ops options and need extra # of people - number of groups of extra people we can choose out of ops people. This gives us all the groups of people (not the orders) who could possible be hanging norm+1 decorations
        // There are more! ways to order those more # of people because we have n=more people and want to arrange all n of them in different orders, which is nPr(more, more) = more! / (more-more)! = more! so we multiply the previous combinations by more!
        // Now we have all the possible orderings of the first more people that hand extra decorations. For each of those orderings, there are different orders of people who only hang norm decorations. There are N-more people (normCnt), and all the different ways to arrange them is normCnt! (similar to the step above). Therefore, you multiply the previous calculation by normCnt!

        // ans = nCr(ops, extra) * more! * normCnt!

        long long ans = C[ops][extra] % MOD;
        ans = (ans * f[more]) % MOD;
        ans = (ans * f[normCnt]) % MOD;

        cout << ans << endl;
    }
}
