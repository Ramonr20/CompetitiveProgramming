#include <bits/stdc++.h>
#define MAXN 41

typedef unsigned long long int ulli;
using namespace std;

ulli dp[MAXN][MAXN];

void pascal() {
    dp[0][0] = 1;

    for(int i = 1; i < MAXN; ++i)
        for(int j = 0; j < i + 1; ++j)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];

}

int main() {
    int T;
    // ulli ans = 0;
    int arr[1001][2];

    pascal();

    cin >> T;

    for(int i = 0; i < T; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }
    for(int i = 0; i < T; ++i) {
       ulli ans = 0;
        for(int j = arr[i][0]; j < (arr[i][1]) + 1; ++j) {
            // cout << "j = " << j << "\n";
            for(int k = 0; k < j + 1; ++k) {
            // cout << "k = " << k << "\n";
                ans += dp[j][k];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}