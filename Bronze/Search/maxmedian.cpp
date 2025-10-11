// I did this CF problem while following the answer key. It was confusing at
// first, but I think I understand it now. Basically, you check every single
// possible value for the maximum median, but instead of wasting a bunch of
// time brute forcing your way through this problem, you sort the numbers
// first, then you use binary search to check in intervals. So you start with
// an answer of 0, then you check if 0+interval is a valid solution. If not,
// you move on to the next interval. If so, you keep checking if ans+interval
// is valid and adding the interval onto ans.

// If I wanted to come up with this solution, I would need to be really
// familiar with binary search and recoginzing binary search problems. I feel
// like a lot of problems could use this strategy, but I definitely need to
// practice a lot more.

#include <bits/stdc++.h>
using namespace std;

int N;
long long K;
vector<long long> a{};

bool check(long long num)
{
    long long changes{0};

    for (int i{(N-1)/2}; i < N; ++i) {
        changes += max(static_cast<long long>(0), num-a[i]);
        if (changes > K) return false;
    } return true;
}

int main()
{
    cin >> N >> K;

    for (int i{0}; i < N; ++i) {
        long long num;
        cin >> num;
        a.push_back(num);
    }

    sort(a.begin(), a.end());

    long long ans{0};
    for (long long i{1000000000}; i >= 1; i /= 2) {
        while (check(ans+i)) {
            ans += i;
        }
    }

    cout << ans << endl;
}
