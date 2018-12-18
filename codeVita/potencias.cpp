#include <bits/stdc++.h>

using namespace std;

int main(){

	int cont = 0, pot = 0, i = 0;
	vector<int> arr;

	while (pot <= 10000000) {
		pot = 1 << i;
		i++;
		arr.push_back(pot);
	}
	
	sort(arr.begin(), arr.end(), [](int a, int b){return a > b;});

	cout << i << '\n';
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << ',';
	cout << '\n';
		
	return 0;
}
