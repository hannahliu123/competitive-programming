// USACO Guide - UNFINISHED

#include <bits/stdc++.h>
using namespace std;

// Addition of 2 integers using bit operations
int add(int a, int b) {
    while (b > 0) {
		int carry = a & b;
		a ^= b;     // positions w/o carry (01 or 10)
		b = carry << 1;     // b holds the value we want to carry over
	}
	return a;
}

int mult(int a, int b) {
	int c = 0;
	while (b > 0) { // keep adding a's value once or twice
		if ((b & 1) == 1) { // add a once (otherwise if 0, skip)
			c = add(c, a);  // Use the addition function we coded previously
		}
		a <<= 1;    // multiply by two for the next iteration
		b >>= 1;    // get rid of 0th bit (already processed)
	}
	return c;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << add(a, b) << endl;
    cout << mult(a, b) << endl;
}
