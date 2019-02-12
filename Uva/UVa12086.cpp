#include <bits/stdc++.h>
#define MAXN 200005

using namespace std;

int ft[MAXN], fr[MAXN];
int N;

int query(int b) {
    int sum = 0;
    while (b > 0) {
        sum += ft[b];
        b -= (b & (-b));
    }
    return sum;
}

void update(int k, int v) {
    while(k <= N) {
        ft[k] += v;
        k += (k & (-k));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int v, x, y, c = 1;
    string op;

    while (cin >> N, N) {
        if (c > 1) cout << '\n';

        for (int i = 1; i <= N; ++i) {
            cin >> fr[i];
            update(i, fr[i]);
        }

        cout << "Case " << c << ":\n";

        while(cin >> op, op != "END") {
            cin >> x >> y;

            if (op == "S") {
                update(x, y - fr[x]);
                fr[x] = y;
            } else if (op == "M"){ 
                cout << (query(y) - query(x - 1)) << '\n';
            }
        }
        memset(ft, 0, sizeof(ft));
        c++;
    }

    return 0;
}