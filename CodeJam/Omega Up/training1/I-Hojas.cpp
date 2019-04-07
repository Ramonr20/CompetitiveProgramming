#include <bits/stdc++.h>

using namespace std;

int main() {

	int N, b, h;
	int ans, cont = 0;

	cin >> N >> b >> h;

	if (b == 10) {
		for (int i = 1; i <= N; ++i) {
			if (i < 10) cont++;
			else if (i > 9 && i < 100) cont += 2;
			else if (i > 99 && i < 1000) cont += 3;
			else if (i == 1000) cont += 4;
		}

		cout << ceil((float)cont / h) << '\n';

	} else if (b == 2) {
		for (int i = 1; i <= N; ++i) {
			if (i < 4) cont += 2;
			else if (i < 8) cont += 3;
			else if (i < 16) cont += 4;
			else if (i < 32) cont += 5;
			else if (i < 64) cont += 6;
			else if (i < 128) cont += 7;
			else if (i < 256) cont += 8;
			else if (i < 512) cont += 9;
			else if (i < 1024) cont += 10; 
		}		
		
		cout << ceil((float)cont / h) << '\n';
	}	

	return 0;
}
