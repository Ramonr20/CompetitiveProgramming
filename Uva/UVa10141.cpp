#include <bits/stdc++.h>

using namespace std;

int main() {

	int N, P, z = 1, nr, auxRM, maxR;
	string s(""), nameP(""), win("");
	double cost, mincost;
	
	while((cin >> N >> P), N && P) {
		
		maxR = 0;
		mincost = DBL_MAX;
		while (N--) { cin.ignore(); getline(cin, s); }
		
		while (P--) {

			getline(cin, nameP);
			scanf("%lf %d", &cost, &nr);
			auxRM = nr;
			while (nr--) { cin.ignore(); getline(cin, s); }

			if (maxR <= auxRM) 
				if (mincost > cost || maxR < auxRM) {
					win = nameP; maxR = auxRM; mincost = cost;						
				}
		}
		if (z > 1) cout << "\n";
		cout << "RFP #" << z++ << "\n";
		cout << win << "\n";
	}
	return 0;
}
