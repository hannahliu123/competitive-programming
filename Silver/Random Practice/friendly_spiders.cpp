// CF - D. Friendly Spiders - R1800

// I tried a naive brute force approach because i thought the time complexity
// would just be O(N+M) which is nodes+edges. that's the normal time complexity
// for BFS because you only visit each node and edge once so i thought my time
// complexity would be O(N+N). In reality, for each node, my code is visiting all
// other N nodes, so it's actually O(N^2). 

// BFS is the right idea but i need a way to optimize it. i prolly wouldn't have 
// gotten this idea without the editorial but you need to caclulate all the prime
// factors (which i never considered could be an option) and then used those somewhat
// as your edges. i just understood how to prime factors code works but it runs in 
// O(sqrtN) time which ive like never encountered much before. i thought finding all
// factors would take absolutely forever (wayyyy over time complexity)

// for using the prime factors kinda as an adjacency list, you need to store the
// factors for each spider as well as have a map that shows all the spiders corresponding
// to each factor. i literally drew this out on paper then thought it wouldn't be an
// option cos i had no idea how to implement it. from here, u can do bfs from the starting
// node and for each of its prime factors, if that factor hasn't been visited already,
// you visit all the spiders that share that factor and continue. you also need to store
// the previous spider for reconstruction 

// The time complexity for this problem if O(N[sqrt(A) + log(N)]) where A is the largest
// number of legs a spider has. this is because for each spider (1->N), we compute all of
// its prime factors which takes sqrt(A) time depending on the numnber of legs (A) it has.
// We also visit every item in factor_map as well as every single individual factor. The
// value of A (largest number of legs) has at most log(A) prime factors, so the BFS part
// is roughly O(N*logA). This is bc we visit all the prime factors of each spider. If you
// combine those complexities (add them together), you get O(N[sqrt(A) + log(N)])

// now how would i be able to get to this on my own. for starters i should have realized
// that naive bfs wasn't an option. i also would've needed to know how to find all prime
// factors in O(sqrt(x)) time. I would also need to know that a number x has at most
// log_2(x) prime factors (i need this to be able to calculate time complexities and the
// explanation for why this is true makes a ton of sense). This means there's a ton of
// content that I just didn't know before going into this problem. But if i did know all
// of that, i think i would be able to solve it because i literally almost connected the
// dots but i doubted myself because i didn't think i could implement that solution 
// within the time complexity

#include <bits/stdc++.h>
using namespace std;

set<int> primes(int n) {
    set<int> factors{};
    while (n % 2 == 0) {
        factors.insert(2);
        n /= 2;
    }
    for (int i{3}; i*i <= n; i+=2) {
        while (n % i == 0) {
            factors.insert(i);
            n /= i;
        }
    }
    if (n > 1) factors.insert(n);
    return factors;
}

int main() {
    int N;
    cin >> N;
    vector<set<int>> prime_factors(N);
    map<int, set<int>> factor_map;
    for (int i{0}; i < N; ++i) {
        int spider;
        cin >> spider;
        prime_factors[i] = primes(spider);
        for (auto& f : prime_factors[i]) factor_map[f].insert(i);
    }

    int S, T;
    cin >> S >> T;
    S--; T--;

    set<int> used;  // stores all visited factors
    vector<int> prev(N, -1);    // for reconstruction
    queue<int> q{};
    prev[S] = -2;
    q.push(S);
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        for (auto& f : prime_factors[n]) {
            if (used.count(f)) continue;    // already visited this factor
            for (auto& i : factor_map[f]) {
                if (prev[i] != -1) continue;
                prev[i] = n;
                q.push(i);
            } used.insert(f);
        }
    }

    if (prev[T] == -1) cout << -1 << endl;
    else {
        deque<int> ans{T+1};
        int p = T;
        while (p != -2) {
            p = prev[p];
            if (p != -2) ans.push_back(p+1);
        }
        
        cout << ans.size() << '\n';
        while (!ans.empty()) {
            cout << ans.back() << ' ';
            ans.pop_back();
        }
    }
}
