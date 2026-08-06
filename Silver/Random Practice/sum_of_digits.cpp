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

// 

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        ;
    }
}