// Problem 3 - UPSOLVE

#include <bits/stdc++.h>
using namespace std;

int A;

bool isBaseAPal(long long n) {
    vector<int> baseA{};
    while (n != 0) {
        baseA.push_back(n % A);
        n /= A;
    }

    vector<int> rev = baseA;
    reverse(rev.begin(), rev.end());

    return baseA == rev;
}

int main() {
    long long N;
    cin >> A >> N;

    long long ans = 0LL;
    // find all palindrones from 1 -> N by breaking it into two halves (from 1 -> sqrtN) then
    // mirror that number so that it becomes a palindrone.
    int lenN = to_string(N).length();
    for (int len{1}; len <= lenN; ++len) {
        // halfLen is the number of digits that we freely choose
        long long halfLen = (len+1)/2;     // ceil because if you want 12321 (for example) as a palindrone, you would bee digits 123 (not just 12)
        
        // Given the length of the number, we need to check all numbers of that length to see if
        // it is a palindrone (from 1 -> 9 OR 10^(halfLen-1) -> 10^(halfLen) - 1)
        long long start = halfLen == 1? 1LL : pow(10LL, halfLen-1);
        long long end = pow(10LL, halfLen) - 1;       // either way if halfLen == 1, end == 9
        for (long long i{start}; i <= end; ++i) {
            // mirror i based on if it's even or odd length (convert to string)
            string left = to_string(i);
            string right = left;
            reverse(right.begin(), right.end());
            // if even, mirror normally. if odd, don't mirror the middle digit
            if (len % 2 == 1) right.erase(0, 1);

            string final = left + right;
            long long num = stoll(final);
            if (num > N) continue;      // too large; skip

            if (isBaseAPal(num)) ans += num;
        }
    }

    cout << ans << endl;
}
