// bro how did this work... im starting to think time and size limits don't matter

// Better solution: three vectors (length of 26); 1 for each "set" of words and one final one. Then set each value of the final one to the max of each "set" vector. Sighhh

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main()
{
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int N;
    cin >> N;

    vector<string> wordL(N);
    vector<string> wordR(N);

    for (int i{0}; i < N; ++i) {cin >> wordL[i] >> wordR[i];} // could've combined this

    vector<int> letters(26);

    string leftWord;
    string rightWord;
    for (int i{0}; i < N; ++i) // with this (and we wouldn't have needed two vectors to store them in)
    {
        vector<int> prev(26);
        leftWord = wordL[i];
        rightWord = wordR[i];

        for (int j{0}; j < leftWord.length(); ++j)
        {
            ++prev[leftWord[j]-97];
            ++letters[leftWord[j]-97];
        }

        for (int j{0}; j < rightWord.length(); ++j)
        {
            if (prev[rightWord[j]-97] > 0)
                --prev[rightWord[j]-97];
            else
                ++letters[rightWord[j]-97];
        }
    }

    for (int i : letters)
    {
        cout << i << '\n';
    }

    return 0; // wait... we don't actually need this uh
}
