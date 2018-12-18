#include <bits/stdc++.h>
#define MAXN 100002
#define X first
#define Y second
#define INF 9999999999
#define PB push_back

using namespace std;

typedef long long int lli;
typedef pair<int, lli> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

int N, M, K, u, v, wh;
lli w;
vi whs;
vvii G(MAXN);

int main() {
	
	lli ans = INF;
	cin >> N >> M >> K;

	for (int i = 0; i < M; ++i) {
		cin >> u >> v;
		cin >> w;
		G[u - 1].PB(ii(v - 1, w));
		G[v - 1].PB(ii(u - 1, w));
	}
	if (K > 0) {
		for (int i = 0; i < K; ++i) {
			cin >> wh;
			whs.PB(wh - 1);
		}
	}
	sort(whs.begin(), whs.end());
	for (int i = 0; i < whs.size(); ++i) {
		for (int j = 0; j < G[whs[i]].size(); ++j) {
			if (ans > G[whs[i]][j].Y && !binary_search(whs.begin(), whs.end(),G[whs[i]][j].X))
				 ans = G[whs[i]][j].Y;
		}
	}
	if (ans == INF) cout << -1 << '\n';
	else cout << ans << '\n';
				
	return 0;
}
