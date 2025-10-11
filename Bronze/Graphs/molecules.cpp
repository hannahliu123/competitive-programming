// CF - 344B - R1200

// Start: 6:55
// End: 7:59        1 hr 4 mins

// Alright so I was super proud of this solution, but like it could've been a lot 
// simpler. I feel like this happens a lot with my solutions. Like I have a right 
// idea, except i just implement it really redundantly. I guess i just get ahead of
// myself and i want to code it immediately after i notice a pattern. But if i
// spent jsut a little more time, i could've figured out a better formula. The 
// editorial uses a lot of math that I don't really know well yet though, like
// tangent and yucky triangle stuff. Ok yeah now that I read more solutions, I 
// don't think that my brain would've been able to come up with that. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> check{a, b, c};
    sort(check.begin(), check.end());

    if (check[0]+check[1] < check[2] || (a+b+c)%2==1) cout << "Impossible" << endl;
    else if (check[0]+check[1] == check[2]) {
        if (a > b && a > c) {   // a largest
            cout << b << " 0 " << c << endl;
        } else if (b > a && b > c) {    // b largest
            cout << a << ' ' << c << " 0" << endl;
        } else {    // c largest
            cout << "0 " << b << ' ' << a << endl;
        }
    } else {
        int bond12 = 0, bond23 = 0, bond31 = 0, diff = 0;
        if (a > b && a > c) {   // a largest
            if (b > c) {
                diff = b-c;
                bond12 = diff + (a-diff)/2;
                bond31 = (a-diff)/2;
                bond23 = c-bond31;
            } else {
                diff = c-b;
                bond31 = diff + (a-diff)/2;
                bond12 = (a-diff)/2;
                bond23 = c-bond31;
            }
        } else if (b > a && b > c) {    // b largest
            if (a > c) {
                diff = a - c;
                bond12 = diff + (b-diff)/2;
                bond23 = (b-diff)/2;
                bond31 = c-bond23;
            } else {
                diff = c - a;
                bond23 = diff + (b-diff)/2;
                bond12 = (b-diff)/2;
                bond31 = c-bond23;
            }
        } else {    // c largest
            if (b > a) {
                diff = b-a;
                bond23 = diff + (c-diff)/2;
                bond31 = (c-diff)/2;
                bond12 = a-bond31;
            } else {
                diff = a-b;
                bond31 = diff + (c-diff)/2;
                bond23 = (c-diff)/2;
                bond12 = a-bond31;
            }
        } cout << bond12 << ' ' << bond23 << ' ' << bond31 << endl;
    }
}
