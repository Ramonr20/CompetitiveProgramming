#include <bits/stdc++.h>


using namespace std;

typedef pair<int, double> id;

vector<id> dep;

int main() {

	int M, noDep, month;
	double  fpm, loan, porcent, pm;
	int i, j, cont;
	double carVal;

	while (cin >> M) {
		if (M < 0) break;

		cin >> fpm >> loan >> noDep;
		carVal = fpm + loan;
		
		while (noDep--) {
			cin >> month >> porcent;
			dep.push_back(id(month, porcent));
		}

		i = j = 1;
		cont = 0;
		pm = loan / M;
		carVal = (carVal - (carVal * dep[0].second));
		while (carVal < loan) { 
			
			if (i == dep[j].first) {
				carVal = (carVal - (carVal * dep[j].second));
				j++;
				i++;
			}else {
				carVal = (carVal - (carVal * dep[j - 1].second));
				i++;
			}
			loan -= pm;
			cont++;
		}
		if (cont != 1) cout << cont << " months\n";
		else cout << cont << " month\n";		

		dep.clear();		
	}

	return 0;
}
