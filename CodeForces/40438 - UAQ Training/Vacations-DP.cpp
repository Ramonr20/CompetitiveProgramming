#include <bits/stdc++.h>
#define MAXN 110
#define FOR(t, i, init, end) for (t i = init; i < end; i++)

using namespace std;

typedef pair<int,int> pii;

int N;
int days[MAXN];
int dp[MAXN][3];

int solve() {

    FOR(int, i, 0, N) {
        dp[i][0] = max(max(dp[i-1][1],dp[i-1][2]),dp[i-1][0]);

        if (days[i] == 1 || days[i] == 3) {
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + 1;
        }
        if (days[i] == 2 || days[i] == 3) {
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + 1;
        }
    }

    return max(max(dp[N-1][0],dp[N-1][1]), dp[N-1][2]);
}

int main() {

    cin >> N;

    FOR (int, i, 0, N) {
        cin >> days[i];
    }

    cout <<  N - solve() << '\n';

    return 0;
}