#include <bits/stdc++.h>

using namespace std;

void adelantar(int d) {
	if (d == 1)
		cout << "ADELANTAR " << d << " SEGUNDO\n";
	else 
		cout << "ADELANTAR " << d << " SEGUNDOS\n";
}
void atrasar(int d) {
	if (d == 1)
		cout << "ATRASAR " << d << " SEGUNDO\n";
	else 
		cout << "ATRASAR " << d << " SEGUNDOS\n";
}
int main() {

	int a, b, dif;
	
	cin >> a;
	cin >> b;
	
	if (a > b) { 
		dif = abs(b - a);
		atrasar(dif);
	}else {
		dif = b - a;
		adelantar(dif);
	}

	return 0;
}
