#include <bits/stdc++.h>

using namespace std;

int main() {
	
	srand (time(NULL));
	cout << 1 << "\n";
	cout << 100000 << "\n";
	for (int i = 0; i < 100000; ++i) {
		cout << rand() % 100000 + 1 << " ";
	}
	cout << "\n\n";
	return 0;
}
