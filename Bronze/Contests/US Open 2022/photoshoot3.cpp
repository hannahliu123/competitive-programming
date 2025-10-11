// After watching the COMPLETE solution and relaizing im sped

// so how could i have come up with this. Well for starters, if i understood the
// question and the answer, then i might've been able to find the pattern. But uh
// I wasn't able to do that. I think misreading the problem can be fixed more
// easily, but idk how i would come to that answer conclusion. ig when i test my
// "answer" I have to be more skeptical that it's definitely correct because now i
// know how frustrating it is to spend so much time on a solution that just doesn't
// work. If i had tried to convert all of the possible pairs to 'T', then I would
// have realized that it actually was possible. I guess im just rushing too much.
// Bruh i literally have 4 hours we're chilling. Relaaax. Don't end up wasting
// even mroe time like this omg. Esp cos when i solve for the wrong thing in a
// wrong way, i use too many of my nonexistent braincells then lose motivation to
// solve the question the *right* way. CMON BE MORE CAREFUL 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;
    
    vector<char> pairs{};
    vector<char> ans{};
    for (int i{0}; i < N-1; i+=2) {
        if (s[i] == s[i+1]) continue;
        else if (s[i] == 'G') pairs.push_back('F');
        else if (s[i] == 'H') pairs.push_back('T');
    }

    for (int i{0}; i < pairs.size(); ++i) {
        if (i==0) ans.push_back(pairs[i]);
        else if (pairs[i]!=pairs[i-1]) ans.push_back(pairs[i]);
    }

    cout << (ans[ans.size()-1]=='T'? ans.size()-1 : ans.size()) << endl;
}
