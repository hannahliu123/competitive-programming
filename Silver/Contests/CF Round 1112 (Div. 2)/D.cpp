// D

// so this problem just seems really complicated and edge case-y. basically what i got was
// that there might be a way to count the combinations via multiplication of possible numbers
// in each index. but the implementation seems really hard for that naive idea and i need to
// optimize it to O(N log N). I feel like i could prolly find a N^2 solution but uh either the
// implementations just really hard or im missing something. i feel like theres an ideal way
// to count the combinations. i have one idea of how to figure out the possible indexes for
// each element in the permutation 1->N but that worst case takes O(N^2) and also idk how to 
// find the final solution using that bc idk if theres a specific way i should process the
// potential locations

// Okay so the first thing i missed was that this problem can involve prefix and suffix maximums.
// The answer at each index is either the prefix max on the left or the suffix max on the right.
// notice that obviously prefix maxes are increasing and suff is decreasing (technically non-
// decreasing then non-increasing but im not saying that for simplicity). Also notice that the
// side with the minimum will ALWAYS just be the side without N, because N will always be a max
// on one side so N can never be the answer for any a[i]. I didn't make that obvious realization.
// I did realize tho that whatever a[i] was, it had to be the max on one side, meaning all values
// above a[i] had to be on the other side. Anyways, so, if N is on the left side, we take the suff
// max of the right side which will be a[i]. If N's on the right side, we take the pref max of i
// on the left side. Notice now that as we loop i from index 0 to N-1, while N is on the right
// side, a[i] will always be pref_mx[i]. But once N becomes on index i or to the left of i, a[i]
// will be suff_mx[i+1]. Because we know the pref_mx is always increasing and suff_mx is always
// decreasing and N must be placed at an index between, then we know N can only be placed at an
// index of the highest value in a[i], which will be a chain of (N-1)s. This restricts the placement
// of N to the starting index of that chain until the ending index + 1 (add 1 because if N is placed
// right behind, it's still valid because the suff_mx can start after all those chains of N-1).
// BUT, even more specifically, N MUST appear at either the starting index of that chain or the
// ending index + 1 and not anywhere in between. this is because if it appears anywhere inbetween
// those end points, it makes other restrictions invalid. It's hard to explain but easy to understand
// if u draw it out. Okay so that limits us to 2 options for placing N and we can get there in O(N)
// time because we're just finding the locations of N-1. We also need to guarentee that array a
// does in fact follow a peak pattern. Once we have 2 locations for N, we can treat these two cases
// seperately because they're both possible

// For each N position, now we know everything to the left is a pref mx array and inclusive and to
// the right is a suff mx array. In these arrays, whenever the mx changes values, we know for sure
// that the element there must be (the new max it changed to). Thus, the potential element at that
// index is fixed. For items where the pref/suff max doesn't change, its value could be any element
// less than the current max. But because numbers are shared between the left side and right side,
// we need to merge the left and right arrays to become 1 non-decreasing (increasing) array. But
// before that, we also need to make sure all fixed numbers appear only on either the left side
// right side or neither or else its invalid

// Now, we can loop thru each element and if it's a new max, it's fixed, so there's only one option.
// if it's not fixed, the number of available items that could fill that slot is x (the value of the
// current pref/suff max) - i (0-indexed index in the merged array). This is because we can only
// chose items less than x (so [1,x-1] so x-1 options) and we've already chosen i values (including
// x), so i-1 valuse not including x. x-1 - (i-1) = x-i. finally multiply all the options we have
// for each index. do this for both placements of N then sum up the results

#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;
int N;
vector<int> a;
long long ans;

void compute_ans(int k) {   // N at index k
    // pref and suff arrays
    vector<int> pref_suff_mx(N-1);
    for (int i=0; i < k; i++) {
        pref_suff_mx[i] = a[i];
    }
    for (int i=N-2; i >= k; i--) {
        pref_suff_mx[i] = a[i];
    }

    // merged array
    vector<int> merged{};
    int l=0, r=N-2;
    while (l < k || r >= k) {
        while (l < k && pref_suff_mx[l] <= pref_suff_mx[r]) {
            merged.push_back(pref_suff_mx[l]); l++;
        }
        while (r >= k && pref_suff_mx[r] <= pref_suff_mx[l]) {
            merged.push_back(pref_suff_mx[r]); r--;
        }
    }

    // find options for each index
    long long contr = 1;
    for (int i=1; i < N-1; i++) {
        if (merged[i] == merged[i-1]) {
            contr = (contr * (merged[i]-i)) % MOD;
        }
    }

    ans = (ans + contr) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        cin >> N;
        a.clear(); a.resize(N-1);
        for (auto& i : a) cin >> i;

        // check if valid
        bool pos = true;
        int n1idx1 = -1, n1idx2 = -1;   // two placements for N
        unordered_set<int> seen{};
        for (int i=0; i < N-1; i++) {
            if (a[i]==N) {
                pos = false; break;
            }
            if (a[i]==N-1) {
                if (n1idx1==-1) n1idx1 = i;
                else if (a[i-1] != N-1) {
                    pos = false; break;
                }
                n1idx2 = i;
            } else if (n1idx1 != -1) { // suff
                if (seen.count(a[i]) || (i+1<N-1 && a[i] < a[i+1])) {
                    pos = false; break;
                }
            } else {    // pref
                seen.insert(a[i]);
                if (i+1<N-1 && a[i] > a[i+1]) {
                    pos = false; break;
                }
            }
        }
        if (!pos || n1idx1==-1) {
            cout << 0 << '\n';
            continue;
        }

        n1idx2++;

        ans = 0;
        compute_ans(n1idx1);
        compute_ans(n1idx2);

        cout << ans << '\n';
    }
}