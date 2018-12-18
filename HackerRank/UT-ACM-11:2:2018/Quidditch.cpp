#include <iostream>

using namespace std;

int S, G;
int dif;

int nedded() {
	int need = 10;
	while (1) {
		dif = G - (S + need);
		if (dif >= 150) {
			need += 10;
		} else {
			return need;
		}
	}
}

int main() {

	cin >> S >> G;

	dif = (G - S);

	if (dif >= 150) {
		cout << nedded() << '\n'; 
	} else {
		cout << "yes\n";
	}

	return 0;
}
