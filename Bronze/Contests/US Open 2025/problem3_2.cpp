// It's Mooin' Time III

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    string s;
    cin >> s;

    vector<int> letter[26];
    for (int i{0}; i < N; ++i) {
        letter[s[i]-'a'].push_back(i);
    }

    vector<char> letters{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    while (Q--) {
        int l, r;
        cin >> l >> r;
        
        --l; --r;
        long long ans = -1;
        for (int j{0}; j<26; ++j) { // last letter ; 0a, 1b, 2c...
            int first{-1};
            if (letter[j].size()>1) {
                int prevlast{-1}, last{-1};
                for (int la : letter[j]) {   // find highest value <=r
                    if (la<=r && prevlast>0 && la-1>l) {
                        last = la;
                    } else if (la<=r && la>l) prevlast = la;
                } if (last != -1) {
                    for (int i{l}; i < last; ++i) {  // find value >=l && !=last
                        if (s[i] != letters[j]) {
                            first = i;
                            break;
                        }
                    } if (first != -1) {
                        int ideal = ((last-first)/2)+first;
                        for (int k{0}; ideal-k>first || ideal+k<last; ++k) {
                            if (ideal+k<last && s[ideal+k] == letters[j]) {
                                long long value = ((ideal+k)-first)*(last-(ideal+k));
                                ans = max(ans, value);
                                break;
                            } else if (ideal-k>first && s[ideal-k] == letters[j]) {
                                long long value = ((ideal-k)-first)*(last-(ideal-k));
                                ans = max(ans, value);
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}
