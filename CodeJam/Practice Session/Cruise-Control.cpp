#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long  ull;

int T, S, N; 
ull D, K;

int main() {

    ull dis;
    double ans, clk, maxTime;
    int i = 1;
    scanf("%d", &T);

    while (T--) {
        scanf("%lld %d", &D, &N);
        maxTime = 0;

        while (N--) {
            scanf("%lld %d", &K, &S);
            dis = D - K;
            clk = (double) dis / S;
            if (maxTime < clk)
                maxTime = clk;
        }
        ans = D / maxTime;
        printf("Case #%d: %f\n", i++, ans);
    }
    return 0;
}