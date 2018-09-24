#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef pair<char, int> ci;
typedef set<int> si;
typedef map<char, int> mci;

vector<ii> eList;
vi V, noNodes;
mci letters;
int N;
string E;
string v;

class UnionFind {
	private: vi p, rank, childP;
	si numOfSets;

	public:
		UnionFind(int N) { 
			rank.assign(N,0);
			p.assign(N, 0);	
			childP.assign(N, 0);
			for (int i = 0; i < N; ++i) { p[i] = i; } 
		}
		int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
		bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

		void unionSet(int i, int j) {
			if (!isSameSet(i, j)) {
				int x = findSet(i), y = findSet(j);
				if (rank[x] > rank[y]) { p[y] = x; childP[x]++; childP[y] = -1; }
				else {
					p[x] = y; childP[y]++; childP[x] = -1;
					if (rank[x] == rank[y]) rank[y]++;
				}
			}
		}
		ii treeAndAcorn() {
			int t = 0, a = 0;
			for (int i = 0; i < noNodes.size(); ++i) {
					if (noNodes[i] == 1)
						childP[i] = -1;
			}
			for (int i = 0; i < childP.size(); ++i) {
				if (childP[i] == 0) a++;
				else if (childP[i] > 0) t++;
			}
			noNodes.clear();
			return ii(t,a);
		}
};

void makeLetters() {
	int j = 0;
	for (char i = 'A'; i <= 'Z'; ++i, ++j)
		letters.insert(ci(i, j));
}

int split(const string& str, char delim) {
	int nl = 0, i = 0, t;
	vector<char> letras;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delim)) {
		letras.emplace_back((char)*token.c_str());
	}
	sort(letras.begin(), letras.end());
	for (auto l : letras){
		t = letters[l];
		if (t != i)for (int j = i; j < t; ++j ) { nl++; i++; noNodes.emplace_back(1); }	
		if (t == i ) { nl++; i++; noNodes.emplace_back(0); }
	}
	letras.clear();
	return nl;
}

int main() {

	makeLetters();
	cin >> N;
	int nv;
	ii ans;
	while (N--) {
		while ((cin >> E), E[0] != '*') {
			eList.emplace_back(letters[E[1]],letters[E[3]]);
		}
		cin >> v;
		nv = split(v,',');	
		UnionFind UFDS (nv);
		for (auto u : eList) {
			UFDS.unionSet(u.first, u.second);
		}
		ans = UFDS.treeAndAcorn();
		cout <<"There are " << ans.first <<" tree(s) and " << ans.second << " acorn(s).\n";
		eList.clear();

	}	
	
	return 0;
}