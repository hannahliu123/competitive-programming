#include <bits/stdc++.h>
using namespace std;

// i learned the idea, so hopefully i don't forget it. my code is super duper
// messy so like formatting might be an issue for more complicated problems. For
// now, tho imma just work on concepts. screw formatting. as long as it works...
// ok maybe not the best mindset but yk what i mean :)

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int area1 = (x2-x1)*(y2-y1);
    
    int x1_2, y1_2, x2_2, y2_2;
    cin >> x1_2 >> y1_2 >> x2_2 >> y2_2;
    int area2 = (x2_2-x1_2)*(y2_2-y1_2);

    int area = area1 + area2;
    
    int x1_t, y1_t, x2_t, y2_t;
    cin >> x1_t >> y1_t >> x2_t >> y2_t;
    
    int width1 = min(x2, x2_t) - max(x1, x1_t);
    int length1 = min(y2, y2_t) - max(y1, y1_t);
    int overlap1 = (length1<0 || width1<0? 0 : length1 * width1);

    int width2 = min(x2_2, x2_t) - max(x1_2, x1_t);
    int length2 = min(y2_2, y2_t) - max(y1_2, y1_t);
    int overlap2 = (length2<0 || width2<0? 0 : length2 * width2);

    cout << area-overlap1-overlap2 << endl;
}
