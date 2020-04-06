#include <bits/stdc++.h>
#define PB push_back
#define MAXN 10002

using namespace std;

typedef vector<int> vi;

vector<vi> MO(MAXN);

int N, M;

int main() {

	int nonZ, key, value, slize;
	vector<int> vKey, vValue;	

	while (cin.eof(), (cin >> M >> N)) {

		for (int i = 0; i < M; ++i) {
			MO[i].assign(N, 0);
			if (cin >> nonZ) {
				for(int j = 0; j < nonZ; ++j) {
					cin >> key;
					vKey.PB(key);
				}
				for (int j = 0; j < nonZ; ++j) {
					cin >> value;
					MO[i][vKey[j] - 1] = value;
				}
			}
			vKey.clear();
		}

		cout << N << ' ' << M << '\n';
		for (int i = 0; i < N; ++i) {
 			int nonZs = 0;
			for (int j = 0; j < M; ++j) {
				if(MO[j][i] != 0) 
					nonZs++, vKey.PB(j+1), vValue.PB(MO[j][i]);
					
			}
			cout << nonZs;
			for (int j = 0; j < vKey.size(); ++j) 
				cout << ' ' << vKey[j];
			cout << '\n';
			if (!vValue.size()) cout << '\n';
			else
				for (int j = 0; j < vValue.size(); ++j) 
					cout << vValue[j] << (j < (vValue.size() - 1) ? ' ' : '\n');
			vValue.clear();
			vKey.clear();
		}
	
		for (int i = 0; i < M; ++i)
			MO[i].clear();

	}

	return 0;
}









