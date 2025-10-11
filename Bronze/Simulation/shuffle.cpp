//YIPPEE LITERALLY THE FIRST TRY MUAHAHAHHAHHAHHA

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int N; // number of cows
    cin >> N;

    vector<int> a(N); //shuffles
    vector<int> id(N);
    for (int i{0}; i < N; ++i) {cin >> a[i];}
    for (int i{0}; i < N; ++i) {cin >> id[i];}

    for (int cow{0}; cow < N; ++cow)
    {
        int cowId{cow};
        for (int shuffle{0}; shuffle < 3; ++shuffle)
        {
            cowId = a[cowId]-1;
        }

        cout << id[cowId] << "\n";
    }

    // if i added another cout << endl; here then it doesn't work because there's an extra newline

    return 0;
}
