#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

typedef unsigned long long int ulli;

ulli dp[MAXN][MAXN];

void pascal() {
    int i, j;
    dp[0][0] = 1;

    for (i = 1; i < MAXN; ++i) {
        for (j = 0; j < i + 1; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
}


string binomialPower(int n) {
    int i, terms;
    ulli expY = 0, expX = n;
    string expansion("");
    
    terms = n + 1;
    // expX = n;
    // expY = 0;

    if (n == 0) {
        return string("1");
    }

    for (i = 0; i < terms; ++i) {
        if (i > 0) {
            expansion += "+";
        }

        if (dp[n][i] != 1) {
            expansion += to_string(int(dp[n][i]));//Mi laptop no soporta ulli
        }

        if (expX > 0) {
            expansion += "x" + (expX != 1 ? ("^" + to_string(expX)) : "");
        }

        if (expY > 0) {
            expansion += "y" + (expY != 1 ? ("^" + to_string(expY)) : "");
        }

        --expX;
        ++expY;
    }
    return expansion;
}

int main() {
    int T, N, i;
    cin >> T;
    pascal();

    for (i = 0; i < T; ++i) {
        cin >> N; 
        cout << binomialPower(N) << "\n";
    }

    return 0;
}





