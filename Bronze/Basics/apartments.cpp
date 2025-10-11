#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int applicants, apartments, k;
    int total{0};

    cin >> applicants >> apartments >> k;

    vector<int> desiredSizes(applicants);
    vector<int> sizes(apartments);

    for (int i{0}; i < applicants; ++i)
        cin >> desiredSizes[i];

    for (int i{0}; i < apartments; ++i)
        cin >> sizes[i];

    for (auto& size : sizes)
    {
        for (int desired{0}; desired < applicants; ++desired)
        {
            if (size >= desiredSizes[desired] - k && size <= desiredSizes[desired] + k)
            {
                desiredSizes.erase(desiredSizes.begin() + desired);
                --applicants;
                ++total;
                desired = applicants;
            }
        }
    }

    cout << total;

    return 0;
}
