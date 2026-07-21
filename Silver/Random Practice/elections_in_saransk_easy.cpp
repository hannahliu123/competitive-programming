// CF - F1. Elections in Saransk (easy version) - R1700

// Okay this problem depended on a very specific number theory counting principle
// realization in order to get the right solution idea. So I did come to the
// realization that every item p_i had to share no prime factors with any other number.
// so for each prime pr, only one element (or zero) in p could contain pr as a divisor.
// Knowing this, i tried to calculate how many ways we could acheive an array p such
// that some element p[i] continaed that factor. The issue here is that this will lead
// to a lot of overcounting when you take into consideration other primes pr. I shouldve
// realized this bottle neck and tried to isolate primes pr such that all combinations
// i make with 1 prime is independent of other primes. To be fair, this is my first
// encounter with a situation like this, so at least now i know that i can isoate 
// senarios that are independent of eachother then multiple the final results together
// to avoid complex overlap issues. plus, i should've noticed that my idea of then going
// in and subtracting/readding my over/undercounts would be way too complicated. I was
// kinda considering this because i remember doing something similar for derangements.

// Okay, so this problem involves isolating all possible prime factors pr. For each pr,
// you want to either assign that prime to none of the elements in p or one of the
// elements. If you assign it to one element, the number of times you can assign it to
// that element are 1, 2, 3... k where k is the expononent on pr in the prime factoriziation
// of a[i]. So say if a[i]=2^3 * 3^2. You could assign pr=2 a total of 3 times to a[i] or
// pr=3 a total of 2 times. Note that once you assign pr to a[i], all other elements can
// NOT have pr as a divisor, so for this isolated pr senario, all other elements just have
// a contribution at this stage of 1. 

// Now the key thing is that once you comupted these contributions for all primes pr, you
// can get the final answer by just multiplying all the results from each pr. This works
// because if pr[2] is the total number of combinations you can make by assigning the prime
// 2 to elements then pr[3] is the same for 3 and so one, multiplying pr[2]*pr[3]*pr[5]...
// gives you all the potential values for each element in p. After all, if the value of
// some element was 1 in pr[2], it could be combined with some combination in pr[3] or p[5]
// and become like a 3, 9, or 15, or 5 or something like that but we know within that senario
// it will never have a multiple of 2 if it was 1 in pr[2]. because each individual combo
// within each pr is valid and they don't interfere with other pr values, we cna just
// multiply them together.

// this is like a really bad explanation, ik, but uh the main takeaway is that you want to
// isolate senarios that are independent of one another but end up telling the whole story.
// oh it can be helping to think of if pr[2]=4, each of those 4 combinations represents a
// section of a number p[i]'s valid ending prime factorization that only contains 2's for now.
// then you can multiple the valid factorizations with those of 3, 5, 7, and so on to create
// more complex factorizations that are all valid

#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, X; cin >> N >> X;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        long long ans = 1;
        for (int i=2; i < 708; i++) {
            long long contr = 1;
            for (int j=0; j < N; j++) {
                while (a[j]%i==0) {
                    a[j] /= i;
                    contr++;
                }
            } 
            ans = (ans*contr)%MOD;
        }
        unordered_map<int,int> leftover{};  // oops i forgor about leftover primes :P
        for (auto& i : a) leftover[i]++;
        for (auto& p : leftover) {
            if (p.first > 1) ans = (ans*(p.second+1))%MOD;
        }

        cout << ans << endl;
    }
}