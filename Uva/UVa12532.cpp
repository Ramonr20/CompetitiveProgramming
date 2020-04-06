#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

int N, K;
int nums[MAXN];
int* ft1 = new int[MAXN];
int* ft2 = new int[MAXN];

int query(int b, int* ft) {
    int sum = 0;
    while (b > 0) {
        sum += ft[b];
        b -= (b & (-b));
        // cout << b << ' ';
    } 
    return sum;
}

void update(int k, int v, int* ft) {
    while (k <= N) {
        ft[k] += v;
        k += (k & (-k));
    }
}

int main() {

    char op;
    int a, b;

    cin >> N >> K;

    for (int i = 1; i < N+1; ++i) {
        cin >> nums[i];
        update(i, nums[i], ft1);
    }   

    while (K--) {
        cin >> op >> a >> b;
        if (op == 'C') {
            update(a, b - nums[a], ft1);
            nums[a] = b;
        } else {
            cout << (query(b, ft1) - query(a - 1, ft1)) << '\n';
        }
        // for (int i = 1; i < N+1; ++i) cout << ft1[i] << ' ';
    }

    cout << '\n';

    return 0;
}