#include <bits/stdc++.h>

using namespace std;

int main() {

	int N, c, r, i = 1, min;
	vector<int> v;

	cin >> N;
	while (N--) {
		cin >> r;
		min = 0;

		while (r--) {
			cin >> c;
			
			if (min < c)
				min = c;
		}
		cout << "Case " << i++ << ": " << min << "\n";
	}

	return 0;
}
