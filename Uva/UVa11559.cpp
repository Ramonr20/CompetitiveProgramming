#include <bits/stdc++.h>

using namespace std;


int main() {

	int N, B, H, W, p, aux;
	int beds[14];
	int i;
	int minCost;

	while (scanf("%d %d %d %d", &N, &B, &H, &W) != EOF) {
		minCost = 20000010;	
		while (H--) {
			i = 0;
			aux = W;

			cin >> p;
			while (aux--)
				cin >> beds[i++];
			for (int j = 0; j < W; ++j) {
				if (beds[j] >= N) { 
					if (minCost > (p * N) )
						minCost = p * N;
					break;
				}
			}
		}
		
		if (minCost > B)
			cout << "stay home\n";
		else
			cout << minCost << "\n";
	}

	return 0;
}
