#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n, a, b, g;
    cin >> n;

    int pts1{0};
    int pts2{0};
    int pts3{0};
    vector<int> game{1, 2, 3};
    for (int i{0}; i < n; ++i)
    {
        cin >> a >> b >> g;
        swap(game[a-1], game[b-1]);

        if (game[g-1] == 1)
            ++pts1;
        if (game[g-1] == 2)
            ++pts2;
        if (game[g-1] == 3)
            ++pts3;
    }

    cout << max(pts1, max(pts2, pts3)) << endl;

    return 0;
}
