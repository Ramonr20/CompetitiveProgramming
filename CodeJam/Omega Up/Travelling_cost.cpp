#include <bits/stdc++.h>

#define INF 10000000000
#define MAXN 502
using namespace std;

typedef long long int lli;

lli G[MAXN][MAXN];
void init() {
    for (int i = 0; i < MAXN; ++i)
        G[i][i] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, A, B, W;
    int U;
    int Q, V;
    int maxN = 1;
    lli ans;
    init();
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> A >> B >> W;
        maxN = max(maxN, max(A, B));
        G[A][B] = W;
        G[B][A] = W;
    }

    for (int k = 0; k <= maxN; k++)
        for (int i = 0; i <= maxN; ++i)
            for (int j = 0; j <= maxN; ++j)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

    cin >> U;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> V;
        ans = min(G[U][V], G[V][U]);
        if (ans != INF)
            cout << ans << "\n";
        else
            cout << "NO PATH\n";    
    }

    return 0;
}
//solucion floyd warshal