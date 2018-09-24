#include <bits/stdc++.h>
#define MAXN 27
#define INF -1

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef queue<int> qi;

vector<vii> G(MAXN);
int vis[MAXN];
qi q; 

int bfs(int start) {
	int cont = 0;

	if (vis[start])
		return INF;

	vis[start] = 1; q.push(start);

	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int j = 0; j < (int)G[u].size(); ++j) {
			ii v = G[u][j];
			if (!vis[v.first]) {
				vis[v.first] = 1;
				q.push(v.first);
				cont++;
			}
		}
	}
	return cont;
}

int to_int(char c) {
	return (int)(c - 'A');
}

int main() {
	
	int N, acorn, trees, tmp;
	string edge, V;
	vi letters;

	cin >> N;
	while (N--) {
		acorn = trees = 0;

		while((cin >> edge), edge[0] != '*') {
			G[to_int(edge[1])].emplace_back(to_int(edge[3]), 0);
			G[to_int(edge[3])].emplace_back(to_int(edge[1]), 0);
		}

		cin >> V;
		
		for (int i = 0; i < V.length(); ++i) {				
			if (V[i] != ',') {
				letters.emplace_back(to_int(V[i]));
			}
		}
		
		for (auto v : letters) {
			tmp = bfs(v);
			if (tmp == INF)
				continue;
			else if (tmp == 0)
				acorn++;
			else
				trees++;
		}
		cout << "There are " << trees << " tree(s)" << " and " << acorn << " acorn(s).\n";
		
		memset(vis, 0, sizeof(vis));

		for (int i = 0; i < MAXN; ++i)
			G[i].clear();

		letters.clear(); 
	}
	return 0;
}



