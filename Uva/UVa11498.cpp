#include <bits/stdc++.h>

using namespace std;

int main() {
    int K, N, M, X, Y;

    while (scanf("%d", &K), K) {
        cin >> N >> M;
        for (int i = 0; i < K; ++i ) {
            cin >> X >> Y;
            if (X == N || Y == M) cout << "divisa\n";
            else if (X > N && Y > M) cout << "NE\n";
            else if (X < N && Y > M) cout << "NO\n";
            else if(X < N && Y < M) cout << "SO\n";
            else cout << "SE\n"; 
        }
    }
    return 0;
}