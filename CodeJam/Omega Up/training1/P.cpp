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
typedef vector<int> vi;

vvii trees(MAXN, vii(MAXN));
int vis[MAXN][MAXN];
double inter [MAXN][MAXN];
int N, ans = 0;

int gk[] = {1, 0, -1, 0};
int gr[] = {0, 1, 0, -1};

inline double xinter(int b2, int b1, double m1, double m2) { return (double)(b2 - b1) / (m1 - m2); }
inline double intersection(int m, double x, double b) { return (double)m * x + b; }

class UnionFind {
	private: 
		vi p, rank;

	public:
		UnionFind(int N) { 
			rank.assign(N,0);
			p.assign(N, 0);	
			for (int i = 0; i < N; ++i) { p[i] = i; } 
		}
		int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
		bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

		void unionSet(int i, int j) {
			if (!isSameSet(i, j)) {
				int x = findSet(i), y = findSet(j);
				if (rank[x] > rank[y])  p[y] = x; 
				else {
					p[x] = y;
					if (rank[x] == rank[y]) rank[y]++;
				}
			}
		}
		void disjointSet(int i) {
			int x = findSet(i);
			if (x != i) p[i] = i;	
		}
};

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

map<int, int> lines;

void bfs(int x, int y) {
	int topx, topy;
	qi qx, qy;
	vis[x][y] = 1; qx.push(x); qy.push(y);
	lines[inter[x][y]]++;

	while (!qx.empty()) {
		topx = qx.front(); qx.pop();
		topy = qy.front(); qy.pop();
		for (int j = 0; j < 2; ++j) {
			x = topx + gk[j];
			y = topy + gr[j];
			if ((x < 0 || x >= N) || (y < 0 || y >= N)) { 
				continue;
			}
			if (vis[x][y] == 0) {	
				if (inter[topx][topy] == inter[x][y]) {
					vis[x][y] = 1;
					lines[inter[x][y]]++;
				}
				qx.push(x);
				qy.push(y);
			}
		}
	}

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
	memset(vis, 0, sizeof(vis));
	bfs(0, 0);
	for (auto i : lines)
			cout << i.Y << ' ';
	cout << '\n';

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << inter[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
