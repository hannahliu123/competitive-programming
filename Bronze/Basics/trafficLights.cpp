// kinda doesn't work and also is wayyy to inefficient :(

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;

    vector<bool> street(x);
    vector<int> positions(n);

    for (int i{0}; i < n; ++i) {cin >> positions[i];}
    street[x - 1] = true;

    for (int position : positions)
    {
        street[position - 1] = true;

        int low{0};
        int high{0};
        int longest{0};

        for (int j{0}; j < x; ++j)
        {
            if (street[j] == true)
            {
                high = j;
                if (high - low > longest)
                    longest = high - low;
                low = high;
            }
        }

        cout << longest << ' ';
    }

    return 0;
}

// Input:
// 8 2
// 3 4
// Output:
// 5 3 3
