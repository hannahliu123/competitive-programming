// find all unique arrangements of the letters of a string using next_permutation

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for next_permutation & sort
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<string> perm;    // vector storing all permutations
    int count{0};           // total number of permutations

    sort(s.begin(), s.end());

    do {
        perm.push_back(s);
        ++count;
    } while (next_permutation(s.begin(), s.end()));

    cout << count << '\n';
    for (auto i : perm)
        cout << i << '\n';
}
