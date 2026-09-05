#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        string s; cin >> s;

        long long inv = 0;
        int zeroes = 0, ones = 0;
        for (int i=N-1; i >= 0; i--) {
            if (a[i]==0) zeroes++;
            else {
                inv += (long long)zeroes;
                ones++;
            }
        }
        int done0 = 0, done1 = 0;
        for (int i=0; i < N; i++) {
            if (a[i]==0) done0++;
            else break;
        }
        for (int i=N-1; i >=0 ; i--) {
            if (a[i]==1) done1++;
            else break;
        }

        cout << inv << ' ';

        int l=done0, r=N-done1-1;
        for (int i=0; i < N; i++) {
            if (s[i]=='1' && inv>0) {
                inv -= (zeroes-done0);
                done1++;
                l++;
                while (a[l]==0 && l < r) {
                    l++; done0++;
                }
            } else if (inv>0) {
                inv -= (ones-done1);
                done0++;
                r--;
                while (a[r]==1 && r > l) {
                    r--; done1++;
                }
            } cout << inv << ' ';
        } cout << '\n';
    }
}