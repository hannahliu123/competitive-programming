// C

// bro i had the right idea but i couldn't figure out why it kept TLE-ing. idk if that's
// a word lol. OK BUT FR it was literally bc of set operations. ive never had issues with
// this before but ig the size of my seen set was just too big and so all the insertions 
// kept piling up. each insertion takes logN time so that makes sense. Let's calculate the
// time complexity of my failed code:
// The outer loop (i) runs about sqrt(N/2) times if you treat the (i+1) as i (basically
//   the same thing). If you do the math, you get 2i^2 <= N which means i <= sqrt(N/2).
//   This means that i goes through about sqrt(N/2) iterations
// The inner loop (j) runs while i^2+j^2<=N, so if it started from 0, j <= sqrt(N-i^2).
//   But because it starts from i+1, j actually goes through sqrt(N-i^2)-i iterations.
// The total time complexity for the loop cannot be calculated as the product of each. 
//   This is bc the inner loop's iterations depends heavily on the outer loop (i). So you
//   have to do some very confusing math instead but i do not understand any of it at all
//   so you can scratch all that and do it a logic based way. You know that i can't surpass
//   sqrtN and j also can't surpass sqrtN (already an overestimate but that's fine). So 
//   now that j isn't dependent on i, you can multiply them and get sqrtN*sqrtN = N
// For each iteration, you insert something into a set which takes O(logN) time, so the 
//   total time complexity is O(N log N). this is too large for N<=10^7

// instead you can waste the memory limit instead :DDD i love doing this it's like a cheat
// code

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    
    vector<int> cnt(N+1,0);
    int tot = 0;
    for (int i{1}; i*i+(i+1)*(i+1) <= N; ++i) {
        for (int j{i+1}; i*i+j*j <= N; ++j) {
            int ans = i*i+j*j;
            if (cnt[ans] == 0) tot++;
            else if (cnt[ans] == 1) tot--;
            cnt[ans]++;
        }
    }

    cout << tot << '\n';
    for (int i{1}; i <= N; ++i) {
        if (cnt[i] == 1) cout << i << ' ';
    } cout << endl;
}
