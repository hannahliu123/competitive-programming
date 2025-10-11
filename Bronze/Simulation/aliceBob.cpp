#include <iostream>
using namespace std;

int main()
{
    int r, s, m, n, p, q;
    cin >> r >> s >> m >> n >> p >> q;

    int ax = 0;
    int ay = 0;
    int bx = r;
    int by = s;

    int seconds{0};

    while (ax < bx && ay < by)
    {
        ax += m;
        ay += n;
        bx -= p;
        by -= q;

        ++seconds;
    }

    if (ax == bx && ay == by)
    {
        cout << seconds << endl;
    } else
    {
        cout << -1 << endl;
    }

    return 0;
}
