#include <bits/stdc++.h>
#define MAXN 110
#define FOR(t, i, init, end) for (t i = init; i < end; i++)
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;

int N;
int days[MAXN];

int solve() {
    pii ytd;
    int ans = 0;

    FOR(int, i, 0, N) {
        if (days[i] == 0) {
            ytd = mp(0,0);
        } else if (days[i] == 1) {
            if (ytd.second == 1) continue;
            else ytd = mp(0,1), ans++;
        } else if (days[i] == 2) {
            if (ytd.first == 1) continue;
            else ytd = mp(1,0), ans++;
        } else if (days[i] == 3) {
            if (ytd.first == 1 & ytd.second == 0) {
                ytd = mp(0,1), ans++;
            } else {
                ytd = mp(1,0), ans++;
            }
        }
    }
    return ans;
}

int main() {

    cin >> N;

    FOR (int, i, 0, N) {
        cin >> days[i];
    }

    cout << N - solve() << '\n';

    return 0;
}