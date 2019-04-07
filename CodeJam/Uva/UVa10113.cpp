#include <bits/stdc++.h>
#define MAXN 62
#define PB push_back
#define GCD(a,b) __gcd(a,b)
#define X first
#define Y second
#define iosbase ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int exchange[MAXN];
int vis[MAXN];
vvii items(MAXN);
int idx = 0;

void dfs(int s) {
	vis[s] = 1;

	for (int j = 0; j < items[s].size(); j++) {
		ii v = items[s][j];
		if (!vis[v.X]) {
			int gcd = GCD(v.Y, items[v.X][j].Y);
			exchange[v.X] = v.Y / gcd;
			exchange[items[v.X][j].X] = items[v.X][j].Y / gcd;
			dfs(v.X);
		}
		
	}

}

int vis1[MAXN];

int searchDfs(int s, int dest) {
	cout << s << ' ' << dest << '\n';
	if (s == dest) return 1;
	vis1[s] = 1;
	
	for (int j = 0; j < items[s].size(); ++j) {
		if (!vis1[items[s][j].X]) {
			searchDfs(items[s][j].X, dest);
		}
	}
	return 0;
}

void print() {

	for (int i = 0; i < idx; ++i) {
		for (int j = 0; j < items[i].size(); ++j)
			cout << "idx: " << i << ' ' << items[i][j].X << ' ' << items[i][j].Y << ' ';

		cout << '\n';
	}	
}

void printExc() {
	for (int i = 0; i < idx; ++i) {
		cout << exchange[i] << ' ';
	}
	cout << '\n';
}

int main() {
	iosbase;

	string exp;
	map<string, int> nameItems;

	while(getline(cin, exp)) {
		if (exp == ".") break;
		istringstream iss(exp);
			
		char assert;

		iss >> assert;

		string nx, ny;
		int xx, xy;
		char op;

		if (assert == '!') {
			iss >> xx >> nx >> op >> xy >> ny;

			if (!nameItems[nx]){
				nameItems[nx] = idx, idx++;
			}
			if (!nameItems[ny]) {
				nameItems[ny] = idx, idx++;
			}
			items[nameItems[nx]].PB(ii(nameItems[ny], xy));
			items[nameItems[ny]].PB(ii(nameItems[nx], xx));
		} else {

			iss >> nx >> op >> ny;
			int s = nameItems[ny];
			int end = nameItems[nx];
			int isIn = searchDfs(s, end);
			cout << isIn << '\n';
			if (isIn) {
				memset(vis1, sizeof vis1, 0);
				dfs(nameItems[nx]);
				cout << exchange[nameItems[nx]] << ' ' << nx << " = " << exchange[nameItems[ny]] << ' ' << ny << '\n';
			} else {
				cout << "? " << nx << " = " << " ? " << ny << '\n';
			}
		}
	}
	cout << "Exchange\n";
	printExc();
	cout << "Items\n";
	print();		

	return 0;
}




