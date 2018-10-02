#include <bits/stdc++.h>
#define MAXN 102
#define PB push_back

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G(MAXN);
vi vis;
vi access;
vvi ans;

void dfs(int s, int x) {
	
	vis[s] = 1;
	for (int j = 0; j < (int)G[s].size(); ++j) {
		if (vis[G[s][j]] == 0) { 
			if (G[s][j] == x) continue;
			if (x == 0) access.PB(G[s][j]);
			dfs(G[s][j], x);
		}
	}
}

int main() {

	int T, N, v, slize;
	char l;

	cin >> T;

	for (int c = 0; c < T; ++c) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				cin >> v;
				if (v)	G[i].PB(j);
		}
		
		vis.assign(N, 0);
		dfs(0, 0);
		ans.PB(vis);
		sort(access.begin(), access.end());
		for (int i = 1, sl = 0; i < N; ++i) {
			vis.assign(N, 0);
			if (i == access[sl]) {
				dfs(0, i);
				sl++;
			
				for (int j = 1, s = 0; j < N; ++j)
					if (j != access[s]) {
						vis[j] = 1;
					}else s++;
			} else {
				for (int j = 0; j < N; ++j)
					vis[j] = 1;
			}
			if (access.empty()) {
				for (int j = 0; j < N; ++j)
						vis[j] = 1;
			}
			ans.PB(vis);
		}
		cout << "Case " << c + 1 << ":\n";
		for (int i = 0; i < N + 1; ++i) {
					
			for (int j = 0; j < (2 * N + 1); ++j) {
				if (j == 0 || j == (2 * N)) cout << '+';
				else cout << '-';
			}
			cout << '\n';
			if (i == N) break;
			for (int j = 0; j < N; ++j) {
				cout << '|';
				if (i == 0 && ans[i][j] == 1) cout << 'Y';
				else if (i == 0 && ans[i][j] == 0) cout << 'N';
				else if (ans[i][j] == 1) cout << 'N';
				else cout << 'Y';
			}
			cout << '|';
			cout << '\n';
		}

		for (int i = 0; i < N; ++i) {
			G[i].clear();
		}
		access.clear();
		ans.clear();
	}

	return 0;
}




