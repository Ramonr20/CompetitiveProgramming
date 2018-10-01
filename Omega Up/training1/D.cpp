#include <bits/stdc++.h>

using namespace std;

vector<int> alum;

int main() {

	int N, a;
	
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> a;
		alum.emplace_back(a);
	}
	
	sort(alum.begin(), alum.end(), [](int a, int b){ return a > b; });
	
	for (int i = 0; i < N; ++i)
		cout << alum[i] << " ";
 
	return 0;
}
