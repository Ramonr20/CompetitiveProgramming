#include <bits/stdc++.h>

using namespace std;


void TroubleSort(vector<int> &arr) {

	bool done = false;
	int aux;
	int z = 0, cont = 0;
	while (!done) {
		done = true;
		for (int i = 0; i < arr.size() - 2; ++i) {
			if (arr[i] > arr[i + 2]) {
				aux = arr[i];
				arr[i] = arr[i + 2];
				arr[i + 2] = aux;
				done = false;
			}
			if (z == 1 && cont > 1000)
					break;
			cont++;
		}
		if (z == 1)
			break;
		z++;
	}	
	
}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T, N, x = 1, n;
	vector<int> arr;
	int  ans;

	cin >> T;
	
	while (T--) {
		ans = -1;
		cin >> N;

		while (N--) {
			cin >> n;	
			arr.push_back(n);
		}

		TroubleSort(arr);

		for (int j = 0; j < arr.size() - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				ans = j;
				break;
			}	
		}
		cout << "Case #" << x++ << ": ";
		if (ans == -1)
			cout << "OK" << "\n";
		else
			cout << ans << "\n";
		arr.clear();
	}

	return 0;
}