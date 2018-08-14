#include <bits/stdc++.h>

using namespace std;

int main() {

    int S, C, masses, i = 1;
    float imbalance, A;

    vector<int> M;
    vector<vector<int> > chambers(5,vector<int>(2));

    while (cin >> C >> S) {
        imbalance = 0;        
        A = 0;
        for (int i = 0; i < S; ++i) {
            cin >> masses;
            A += masses;
            M.push_back(masses);
        }
        A /= C;

        if (S < (2 * C)) {
            for (int i = 0; i < ((2 * C) - S);++i) {
                M.push_back(0);
            }
        }
        sort(M.begin(), M.end());
        
        for (int i = 0; i < (M.size() / 2); i++) {
            imbalance += (float) abs((M[i] + M[(M.size() - 1) - i]) - A);
            chambers[i][0] = M[i];
            chambers[i][1] = M[(M.size() - 1) - i];
        }
        
        printf("Set #%i\n", i++);

        for(int j = 0; j < C; ++j) {            
            printf(" %i: ", j);
            if (chambers[j][0] != 0)
                printf("%i ", chambers[j][0]);
            if (chambers[j][1] != 0)
                printf("%i\n", chambers[j][1]);
        }
        cout << "IMBALANACE = " << setprecision(5) << fixed << imbalance << "\n\n";

        M.clear();
        for(int i = 0; i < chambers.size(); ++i) {
            chambers[i][0] = chambers[i][1] = 0;
        }
    }
}   