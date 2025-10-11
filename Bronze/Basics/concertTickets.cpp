#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() 
{
    int tickets, customers;
    cin >> tickets >> customers;

    multiset<int> prices;
    vector<int> maxPrices(customers);

    for (int i{0}; i < tickets; ++i)
    {
        int price;
        cin >> price;
        prices.insert(price);
    }

    for (int i{0}; i < customers; ++i) {cin >> maxPrices[i];}

    for (const auto& max : maxPrices)
    {
        if (!prices.empty() && *prices.begin() <= max)
        {
            if ((*prices.lower_bound(max)) == max)
            {
                auto erase = prices.find(max);
                cout << max << endl;
                prices.erase(erase);
            } else {
                int price = *(--prices.lower_bound(max));
                auto erase = prices.find(price);
                cout << price << endl;
                prices.erase(erase);
            }
        }
        else {cout << -1 << endl;}
    }

    return 0;
}

// 5 3
// 5 3 7 8 5
// 4 8 3
