// Moo Language Upsolving (REDO)

// Start: 5:30
// End: 6:58        1 hr 28 mins

// Let's just reflect on how I could've implmented this better. Erm so yeah if i had
// identified this as just brute forcing every possible combinations of the max words
// for each number of sentence 1 types, i could've gotten it. My implementation was 
// like sadly slow, but uh we figured it out. Yeah wth why'd that take soo long omg

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, C, P;    // words, commas, periods
        cin >> N >> C >> P;

        vector<string> noun{};
        vector<string> tverb{};
        vector<string> iverb{};     // noun iverb.
        vector<string> conj{};
        for (int i{0}; i < N; ++i) {
            string word, type;
            cin >> word >> type;
            if (type == "noun") noun.push_back(word);
            else if (type == "transitive-verb") tverb.push_back(word);
            else if (type == "intransitive-verb") iverb.push_back(word);
            else conj.push_back(word);
        }

        int ans{0}; // max words used
        int nouns = 0, iverbs = 0, tverbs = 0, conjs = 0, commas = 0;
        for (int i{0}; i <= iverb.size(); ++i) {
            int n1 = 0, tv1 = 0, iv1 = 0, cj1 = 0, com1 = 0;
            int n = noun.size(), tv = tverb.size(), cj = conj.size();
            int words = 0, mxsent = P + min(P, cj), sentleft = mxsent;
            int x = min(sentleft, min(n, i));  // use iv
            iv1 += x;
            sentleft -= x;
            words += 2*x;
            n -= x;
            n1 += x;
            x = min(sentleft, min(n/2, tv));   // use max tv
            tv1 += x;
            sentleft -= x;
            words += 3*x;
            n -= 2*x;
            n1 += 2*x;
            x = min((mxsent-sentleft)/2, cj);  // use conj
            cj1 += x;
            words += x;
            if (tv1 > 0) {  // use commas/remaining nouns
                x = min(C, n);
                n1 += x;
                words += x;
                com1 = x;
            }

            if (words > ans) {
                ans = words;
                nouns = n1;
                iverbs = iv1;
                tverbs = tv1;
                conjs = cj1;
                commas = com1;
            }
        }

        cout << ans << '\n';

        // construct sentences
        vector<string> isentences{};
        for (int i{0}; i < iverbs; ++i) {
            string s{};
            s += noun[noun.size()-1];
            noun.pop_back();
            s += ' ';
            s += iverb[iverb.size()-1];
            iverb.pop_back();
            isentences.push_back(s);
        } 
        vector<string> tsentences{};
        for (int i{0}; i < tverbs; ++i) {
            string s{};
            s += noun[noun.size()-1];
            noun.pop_back();
            s += ' ';
            s += tverb[tverb.size()-1];
            tverb.pop_back();
            s += ' ';
            s += noun[noun.size()-1];
            noun.pop_back();
            tsentences.push_back(s);
        }

        // add commas and extra nouns
        for (int i{0}; i < commas; ++i) {
            string s = tsentences[0];
            s += ", ";
            s += noun[noun.size()-1];
            noun.pop_back();
            tsentences[0] = s;
        }

        for (string s : tsentences) isentences.push_back(s);

        // create sentences w/ conj
        int j{0};
        for (int i{0}; i < conjs; ++i) {
            isentences[j] += ' ';
            isentences[j] += conj[conj.size()-1];
            conj.pop_back();
            isentences[j] += ' ';
            isentences[j] += isentences[isentences.size()-1];
            isentences.pop_back();
            ++j;
        }

        // print all sentences
        for (int i{0}; i < isentences.size(); ++i) {
            cout << isentences[i] << (i == isentences.size()-1? "." : ". ");
        }

        cout << '\n';
    }
}
