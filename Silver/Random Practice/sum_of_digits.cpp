// E. Sum of Digits (and Again) - R1800

// because x could be any really large positive number, we can't try to
// test/determine the value of x. also, going off of the very last number
// 1-9 won't work either because it gets increasingly complicated because
// there are so many ways to construct each number especially when |s| is
// so big. What we can do instead is try to determine the number after x 
// because that number can only have a maximum value of 9*|s| (not even
// but we'll go with that). That means it's possible to loop through every
// single possible value of the second number. But we need a way to determine
// if each possibility is valid or not within O(log|s|) time or O(1) time.

// maybe we can precompute the next number for every number from 10 to 9*|s|
// cos each number has a max length of 6, which is essentially O(1). then
// from the number after x, we can keep following the next and next numbers
// and use up all digits until we get to the end. then we see if the sum of
// remaining digits is either zero (the number we started with was actually x)
// or if it adds up to the number we started with. Now, for each possibility,
// we don't want to loop thru every digit of each of the numbers... wait actually
// after x, the next numbers should be really short. in the worst case senario u
// have 899999 then 53 then 8 so we lowkey could just simulate it in O(10ish) time.
// k lemme try that

// omg bro this solution pissed me off (kinda) just cos of that one edge case and 
// also the time complexity thing for string(int, char) i missed. the time 
// complexity thing was pretty obvious to find cos it makes sense that takes O(N)
// time where N is the numebr of time u wanna duplicate that character. The edge
// case tho was just that the starting sum that equals i and should be the number x
// could be zero if either the given string was too short (only two combined values).
// wait i think a valid solution would just be to start the loop from 1 then we would
// never have the next value be not actually the second value cos we already account
// for the case if s is just 1 character. wait lemme try that yeahhhh okay that worked

// okay main takeaway here was to just realize how quickly the length of the
// consecutive strings decreases. like the first one could be crazy long but the second
// has a max vlaue of 9*10^5 (not even technically) then the next one has a max value
// of length 2 then length 2 then length 1. if you notice that combined with the fact
// this is really easy to simulate/brute force, u basically have the solution! So it 
// would've been helpful to make generalizations about the constraints of this problem

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        if (s.length() == 1) {
            cout << s << '\n';
            continue;
        }

        vector<int> cnt(10, 0);
        for (auto& i : s) cnt[i-'0']++;

        for (int i=1; i <= 900000; i++) {
            vector<int> curr_cnt(10, 0);
            bool pos = true;
            string x="", fin="";
            int sum = i;
            while (sum > 9) {
                x = to_string(sum);
                fin += x;
                sum = 0;
                for (auto& j : x) {
                    sum += j-'0';
                    curr_cnt[j-'0']++;
                    if (curr_cnt[j-'0'] > cnt[j-'0']) {
                        pos = false; break;
                    }
                } if (!pos) break;
            } if (!pos) continue;
            curr_cnt[sum]++;
            string last = to_string(sum);
            if (curr_cnt[sum] > cnt[sum]) continue;

            sum = 0;
            for (int j=9; j >= 0; j--) {
                int extra = cnt[j] - curr_cnt[j];
                sum += extra*j;
            }

            if (sum == i) {
                string start="";
                for (int j=9; j >= 0; j--) {
                    int extra = cnt[j] - curr_cnt[j];
                    start += string(extra, j+'0');
                }
                cout << start << fin << last << '\n';
                break;
            }
        }
    }
}