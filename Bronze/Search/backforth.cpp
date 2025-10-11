// Level: Normal (Complete Search with Recursion)
// December 2018 Problem 3

// Girl i need so much more practice with recursion. The solution I copied isn't
// even recursion because i gave up so hard. It's a more big brain solution that
// took me forever to understand. How cooked am i...

#include <iostream>
#include <cstdio>
#include <vector>
#include <set> // an array but without repetition
using namespace std;

int main()
{
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    vector<int> buckets1(10);
    vector<int> buckets2(10);

    for (int i{0}; i < 10; ++i) {cin >> buckets1[i];}
    for (int i{0}; i < 10; ++i) {cin >> buckets2[i];}

    set<int> possible;
    possible.insert(1000); // if same bucket is passed around for four days
    for (int i{0}; i < 10; ++i) {
        for (int j{0}; j < 10; ++j) {
            possible.insert(1000-buckets1[i]+buckets2[j]);  
            // if the same two buckets are passed around

            for (int k{i+1}; k < 10; ++k) {         
            // NOTICE: i+1, not 0. This ensures that the same bucket in Tuesday's 
            // transfer is not picked in Thursday's transfer (because it will no 
            // longer be there). Using i+1 ensures its index will never be chosen.
                for (int l{j+1}; l < 10; ++l) {
                    possible.insert(1000-buckets1[i]+buckets2[j]-buckets1[k]+buckets2[l]);
                }
            }
        }
    }
    cout << possible.size() << endl;
}
