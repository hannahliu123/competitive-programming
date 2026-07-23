// CF - D. Ghostfires - R1800

// Okay so i realized i could pair up colors in some way to form the maximum number of
// pairs with 0 or 1 extra remaining (unless one r, g, or b is much greater than the sum
// of the two others). But i was stuck because this seemed like such a simple greedy
// problem, but when it came to actually forming the pairs, i didn't know what to do.

// okay so the solution is that first we can directly calculate the number of rg, rb, and
// gb pairs by choosing the two colors with the most remaining balls at the time and pairing
// them together. this works because there are only three options and so every color can pair
// with any other color. if we pair the two largest together it'll always be optimal. its also
// key to notice that we might end up with 1 (or more) leftover. we can accomodate up to 1
// extra by just slapping it in the front. but now, to actually construct the string, this is
// the annoying part that kinda pisses me off. because there's only three options you can just
// simulate what it would look like for each of these three options/starting letters.

// obvioulsly if we didn't have a letter we needed to use to start, we could just start with
// any arbitrary pair. if we did have a letter tho, it's optimal for us to pick a the two pairs
// that contain that letter at first, then based on if we had both of those two pairs available,
// pick the orientation of the last pair. the implementation could've looked really really messy
// if i didn't look at the editorial but this is just one of those stupidly annoying problems :(

// i guess the takeaway is that if there are really few options (ex. in this case only 3 colors)
// then its okay to just have if statements for each case. but even then, you want to simplify
// it as much as possible so you dont have ifs within ifs. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int R, G, B; cin >> R >> G >> B;

        int rg = 0, gb = 0, br = 0;
        // while (R+B+G > 1) {
        //     if ((R==0 && G==0) || (R==0 && B==0) || (B==0 && G==0)) break;
        //     while (R <= G && R <= B && G>0 && B>0) {
        //         gb++; G--; B--;
        //     } while (G <= R && G <= B && R>0 && B>0) {
        //         br++; R--; B--;
        //     } while (B <= R && B <= G && G>0 && R>0) {
        //         rg++; R--; G--;
        //     }
        // }

        int mx_pairs = 0;
        for (int i=0; i <= min(R,B); i++) {
            int br1=i;
            int rg1=min(R-br1, G);
            int gb1=min(G-rg1, B-br1);
            if (br1+rg1+gb1 > mx_pairs) {
                mx_pairs = br1+rg1+gb1;
                br=br1; rg=rg1; gb=gb1;
            }
        }

        char start = 'x';
        // if (R > 0) start = 'R';
        // if (G > 0) start = 'G';
        // if (B > 0) start = 'B';
        if (br+rg < R) start = 'R';
        if (rg+gb < G) start = 'G';
        if (br+gb < B) start = 'B';

        if (start=='x') start = 'R';
        else cout << start;

        if (start=='R') {
            for (int i=0; i < rg; i++) cout << "GR";
            for (int i=0; i < br; i++) cout << "BR";
            string last = "GB";
            if (br > 0) last = "BG";
            for (int i=0; i < gb; i++) cout << last;
        } else if (start=='G') {
            for (int i=0; i < rg; i++) cout << "RG";
            for (int i=0; i < gb; i++) cout << "BG";
            string last = "RB";
            if (gb > 0) last = "BR";
            for (int i=0; i < br; i++) cout << last;
        } else {    // B
            for (int i=0; i < br; i++) cout << "RB";
            for (int i=0; i < gb; i++) cout << "GB";
            string last = "RG";
            if (gb > 0) last = "GR";
            for (int i=0; i < rg; i++) cout << last;
        }

        cout << '\n';
    }
}
