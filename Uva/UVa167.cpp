#include <bits/stdc++.h>
#define PB push_back
#define Y first
#define X second 
#define optimize_io ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef pair<int, int> ii;

int cheesboard[10][10];
bool vis[10][10];
vector<ii> queens;

int N, ans;

bool noThreat(int y, int x) {
    for (int i = 0; i < queens.size(); ++i) {
        if ( ((queens[i].Y == y) || (queens[i].X == x)) ) {
            return false;
        } else {
            if ( abs( (queens[i].Y - y) / (queens[i].X - x) ) == 1) {
                return false;
            }
        }
    }
    return true;
}

void solve(int x, int score) {

    if (x == 8) {
        cout << "here\n";
        if (score > ans) {
            ans = score;
        }
        queens.clear();
        return;
    }

    for (int y = 0; y < 8; ++y) {
        if ( !vis[y][x] && noThreat(y, x)) {
            queens.PB(ii(y, x));
            vis[y][x] = true;
            solve(x + 1, score + cheesboard[y][x]);
            vis[y][x] = false;
        }
    }

}

int main() {
    optimize_io

    cin >> N;

    while (N--) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cin >> cheesboard[i][j];
            }
        }

        ans = 0;
        solve(0, 0);
        //cout << "     " << ans << '\n';
    }


    return 0;
}
