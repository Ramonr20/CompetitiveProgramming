#include <bits/stdc++.h>

using namespace std;

int GCD(int M, int N) { return N == 0 ? M : GCD(N, M % N); }

int main() {

    int gcd, M, N;    

    while (cin >> M && cin >> N) {
        cout << GCD(M, N) << "\n";
    }

    return 0;
}
