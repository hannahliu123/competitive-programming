#include <bits/stdc++.h>
using namespace std;

int main() 
{
    map<int, int> numbers{
        {1, 2}, 
        {9, 4}, 
    };

    numbers.insert({5, 6});
    
    numbers[1] = 5;

    for (auto nums : numbers) {     // CANNOT INDEX A MAP
        cout << nums.first << ' ' << nums.second << '\n'; 
    }

    cout << "The value at a key of 9 is " << numbers[9] << '\n';
}
