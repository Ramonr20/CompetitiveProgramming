#include <bits/stdc++.h>
#define MAXN 702
#define X first
#define Y second
#define INF -1
#define PB push_back

using namespace std;

typedef pair<int, double> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef queue<int> qi;


vvii trees(MAXN, vii(MAXN));
int vis[MAXN][MAXN];
double inter [MAXN][MAXN];
int N, ans = 0;

int gk[] = {1, 0, -1, 0};
int gr[] = {0, 1, 0, -1};

inline double xinter(int b2, int b1, double m1, double m2) { return (double)(b2 - b1) / (m1 - m2); }
inline double intersection(int m, double x, double b) { return (double)m * x + b; }

void bfsForInter(int x, int y) {
	int topx, topy;
	double xi, intersec;
	topx = x;
	topy = y; 
	for (int j = 0; j < 2; ++j) {
		xi = 0; intersec = 0;
		x = topx + gk[j];
		y = topy + gr[j];
		if ((x < 0 || x >= N) || (y < 0 || y >= N)) { 
			continue;
		}
		xi = xinter(trees[x][y].X, trees[topx][topy].X, trees[topx][topy].Y, trees[x][y].Y);
		if (!(exp(-xi) == 0) && abs(xi) > 0) {
			intersec = intersection(trees[x][y].Y, xi, trees[x][y].X);
		}
		if (intersec > 0) { 
			inter[topx][topy] = intersec;
			inter[x][y] = intersec;
		}
	}
}

int bfs(int x, int y) {
	int topx, topy;
	qi qx, qy;
	int cont = 1;
	//memset(vis, 0, sizeof(vis));
	vis [x][y] = 1; 
	qx.push(x); qy.push(y);

	while (!qx.empty()) {
		topx = qx.front(); qx.pop();
		topy = qy.front(); qy.pop();
		
		for (int j = 0; j < 2; ++j) {
			x = topx + gk[j];
			y = topy + gr[j];
			//if (!(x < 0 || x >= N) && !(y < 0 || y >= N)) {
				if (vis[x][y] == 0 && inter[x][y] == inter[topx][topy]) cont++;
				if (vis[x][y] == 0) {
					vis[x][y] = 1;
					qx.push(x);
					qy.push(y);
				}	
			//}
		}
	}
	return cont;
}

int main() {

	int x, tmp;

	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> trees[i][j].X;
		}
	}
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> trees[i][j].Y;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			bfsForInter(i, j);
		}
	}

	//memset(vis, 0, sizeof(vis));
	//ans = bfs(0, 0);
	
	//cout << ans << '\n';
	cout << "Aqui\n"; 	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << inter[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
