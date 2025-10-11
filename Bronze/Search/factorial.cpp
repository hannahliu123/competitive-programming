// Nice Video: https://www.youtube.com/watch?v=yBWlPte6FhA

#include <iostream>
#include <vector>
using namespace std;

int factorial(int n)
{
    if (n == 1) // base case (where you are working towards)
        return 1;
    return n * factorial(n-1); // recursive call
}

int main()
{
    int n;
    cin >> n;

    cout << factorial(n);
}
