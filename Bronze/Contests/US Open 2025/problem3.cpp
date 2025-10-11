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
        for (int i{0}; i<26; ++i) {
            if (letter[i].size()>0 && letter[i][letter[i].size()-1]>=l) {
                long long first{};
                for (int f : letter[i]) {   // find value >= l
                    if (f >= l) {
                        first = f;
                        break;
                    }
                } for (int j{0}; j<26; ++j) {
                    if (j!=i && letter[j].size()>1) {
                        long long last{};
                        for (int la : letter[j]) {   // find highest value <=r and >first
                            if (la-1>first && la<=r) {
                                last = la;
                            }
                        }
                        long long ideal = ((last-first)/2)+first;
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

// X - 6
// T - 7-11
