#include <bits/stdc++.h>

#define pb push_back

using namespace std;

// vector<vector<int> > mat(1000, vector<int>(1000, false));


int up(vector<vector<int> > mat, int x, int y) {

	int cont = 0;
	for (int i = y; i < 3; ++i)
		if ( mat[x][i] == true)
			cont++;
	return cont;
}

int main() {

	int T, A, I, J, IP, JP;
	int cases, cont = 0;	
	int x, y;
	int z = 0;
	cin >> T;

	while (T--) {
		vector<vector<int> > mat(1000, vector<int>(1000, false));

		cases = 1001;
		cin >> A;
		
		I = J = A / 2;
		cout << I << " " << J << "\n";
		cin >> IP >> JP;
		mat[IP][JP] = true;
		cases--;
		while (cases--) {
			
			if (mat[I][J] == true) {
				if (z < 2) {
					if (up(mat, I, J) == 3 && (I > 2 && J > 2)) {
						J = J - 1;
						z++;
					}
				}else {
					if (mat[I+1][J] == false && I < 999)
						I = I + 1;
					else if (mat[I-1][J] == false && I > 2)
						I = I - 1;
					else if (mat[I][J + 1] == false && J < 900)
						J = J + 1;
					else if (mat[I][J - 1] == false && J > 2)
						J = J - 1;
				}
			}
			cout << I << " " << J << "\n";

			cin >> IP >> JP;
			mat[IP][JP] = true;

			if (IP == 0 && JP == 0)
				break; 
			else if (IP == -1 && JP == -1)
				break;
		}
		mat.clear();
		if (IP == -1 && JP == -1)
			break;
	}	
	return 0;
}
