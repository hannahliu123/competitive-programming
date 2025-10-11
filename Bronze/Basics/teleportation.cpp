//Commented out section works but is really stupido (my original code 😢)

#include <iostream>
#include <cstdio>
#include <algorithm> //for abs() and min()
using namespace std;

int main()
{
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int answer{abs(a-b)};
    answer = min(answer, (abs(a - c) + abs(b - d)));
    answer = min(answer, (abs(a - d) + abs(b - c)));

    cout << answer;

    // if ((a < b? a : b) >= (c > d? c : d)) {
    //     cout << abs(a-b);
    // } else if ((a > b? a : b) <= (c < d? c : d)) {
    //     cout << abs(a-b);
    // } else {
    //     int dist1{abs(a-c)<abs(a-d)? abs(a-c) : abs(a-d)};
    //     int dist2{abs(b-c)<abs(b-d)? abs(b-c) : abs(b-d)};

    //     cout << dist1 + dist2;
    // }
}
