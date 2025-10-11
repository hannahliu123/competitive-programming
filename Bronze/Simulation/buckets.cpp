#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N; // number of buckets
    cin >> N;

    vector<int> C(N); // capacities
    vector<int> A(N); // water level
    for (int i{0}; i < N; ++i) {cin >> C[i];}
    for (int i{0}; i < N; ++i) {cin >> A[i];}

    int amount{0};

    for (int i{0}; i < N; ++i)
    {
        int amt = min(A[i], C[i+1] - A[i+1]);

        A[i] -= amt;
        A[i+1] += amt;
    }

    for (int i{0}; i < N; ++i)
    {
        cout << A[i] << ' ';
    }

    cout << endl;

    return 0;
}
