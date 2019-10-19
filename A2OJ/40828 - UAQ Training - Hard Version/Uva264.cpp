#include <bits/stdc++.h>

using namespace std;

typedef long int li;

int gauss(int n) { return (n*(n+1)) / 2;}

int main() {

	li cn;
	int a, b;

	while(scanf("%ld", &cn) != EOF) {
		int row = 1;
		int sum = gauss(row);

		if (cn == 1) {
			cout << "TERM " << cn <<  " IS " << "1/1\n";
		} else {

			while (sum < cn) {
				row++;
				sum = gauss(row);
			}

			sum = gauss(row-1);
			int pos = cn - sum;

			if (row % 2 == 0) {
				a = pos;
				b = row - (pos-1);
			} else {
				a = row - (pos-1);
				b = pos;
			}

			cout << "TERM " << cn  << " IS "<< a << '/' << b << '\n';
		}
	}
	
	return 0;
}
