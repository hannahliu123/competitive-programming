// Problem 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("reflection.in", "r", stdin);
    //freopen("reflection.out", "w", stdout);

    int N, U;   // NxN, Updates
    cin >> N >> U;

    bool painting[N][N];
    int freq[N/2][N/2];
    bool optimal[N/2][N/2];

    for (int i{0}; i < N; ++i) {
        for (int j{0}; j < N; ++j) {
            painting[i][j] = 0;
            char temp;
            cin >> temp;
            if (temp == '#') {painting[i][j] = 1;}
        }
    }

    // Loop through each update

    for (int i{-1}; i < U; ++i) {
        if (i != -1) {
            int r, c;
            cin >> r >> c;

            if (painting[r-1][c-1] == 0) painting[r-1][c-1] = 1;
            else painting[r-1][c-1] = 0;
        }

        // calculate full_optimal  ***********************

        for (int i{0}; i < N/2; ++i) {
            for (int j{0}; j < N/2; ++j) {
                freq[i][j] = 0;
                optimal[i][j] = 0;
            }
        }
    
        int row = 0;
        int column = 0;
        for (int i{0}; i < N/2; ++i) {      // Q1
            for (int j{N/2}; j < N; ++j) {
                if (painting[i][j] == 1) {freq[row][column]++;}
                if (column < N/2-1) column++;
                else column = 0;
            }
            row++;
        }
    
        row = 0;
        column = 0;
        for (int i{0}; i < N/2; ++i) {      // Q2
            for (int j{(N/2)-1}; j >= 0; --j) {
                if (painting[i][j] == 1) {freq[row][column]++;}
                if (column < N/2-1) column++;
                else column = 0;
            }
            row++;
        }
    
        row = 0;
        column = 0;
        for (int i{N-1}; i >= N/2; --i) {      // Q3
            for (int j{N/2-1}; j >= 0; --j) {
                if (painting[i][j] == 1) {freq[row][column]++;}
                if (column < N/2-1) column++;
                else column = 0;
            }
            row++;
        }
    
        row = 0;
        column = 0;
        for (int i{N-1}; i >= N/2; --i) {      // Q4
            for (int j{N/2}; j < N; ++j) {
                if (painting[i][j] == 1) {freq[row][column]++;}
                if (column < N/2-1) column++;
                else column = 0;
            }
            row++;
        }
    
        // Find optimal
    
        for (int i{0}; i < N/2; ++i) {
            for (int j{0}; j < N/2; ++j) {
                if (freq[i][j] > (N==2? 2 : (N*N)/8)) {optimal[i][j] = 1;}
            }
        }
    
        // Create full_optimal from optimal
        
        bool full_optimal[N][N];
        
        row = 0;
        column = 0;
        for (int i{0}; i < N/2; ++i) {      // Q1
            for (int j{N/2}; j < N; ++j) {
                full_optimal[i][j] = 0;
                full_optimal[i][j] = optimal[row][column];
                if (column < N/2-1) column++;
                else column = 0;
            }
            row++;
        }
    
        row = 0;
        column = 0;
        for (int i{0}; i < N/2; ++i) {          // Q2
            for (int j{N/2-1}; j >= 0; --j) {
                full_optimal[i][j] = 0;
                full_optimal[i][j] = optimal[row][column];
                if (column < N/2-1) column++;
                else column = 0;
            }
            row++;
        }
    
        row = 0;
        column = 0;
        for (int i{N-1}; i >= N/2; --i) {      // Q3
            for (int j{N/2-1}; j >= 0; --j) {
                full_optimal[i][j] = 0;
                full_optimal[i][j] = optimal[row][column];
                if (column < N/2-1) column++;
                else column = 0;
            }
            row++;
        }
    
        row = 0;
        column = 0;
        for (int i{N-1}; i >= N/2; --i) {      // Q4
            for (int j{N/2}; j < N; ++j) {
                full_optimal[i][j] = 0;
                full_optimal[i][j] = optimal[row][column];
                if (column < N/2-1) column++;
                else column = 0;
            }
            row++;
        }
    
        // Count the number of changes needed to reach full_optimal from original
        
        int changes = 0;
        for (int i{0}; i < N; ++i) {
            for (int j{0}; j < N; ++j) {
                if (painting[i][j] != full_optimal[i][j]) changes++;
            }
        }

        // ***********************

        cout << changes << '\n';
    }

}
