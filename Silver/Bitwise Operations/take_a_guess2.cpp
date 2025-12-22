// CF - D. Take a Guess - R1800

// trial two cos im relearning bitwise operators

#include <bits/stdc++.h>
using namespace std;

int sum(int a, int b) {
    int and_, or_, xor_; a++; b++;
    cout << "and " << a << ' ' << b << endl;
    cin >> and_;
    cout << "or " << a << ' ' << b << endl;
    cin >> or_;

    xor_ = ~and_ & or_;
    return 2*and_ + xor_;
}

int main() {
    int N, K;
    cin >> N >> K;
    K--;

    // find first three values using a systems of equations
    int ab = sum(0,1);
    int ac = sum(0,2);
    int bc = sum(1,2);

    vector<int> a{(ab+ac-bc)/2};    // 1 + 2 + 1 + 3 - 2 - 3 = 2(1)
    a.push_back(ab-a[0]);   // 1 + 2 - 1 = 2
    a.push_back(ac-a[0]);   // 1 + 3 - 1 = 3

    // find remaining elements by comparing it to a known element
    for (int i{3}; i < N; ++i) a.push_back(sum(0,i)-a[0]);

    sort(a.begin(), a.end());   // l -> g
    cout << "finish " << a[K] << endl;
}
