#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
	return b == 0 ? a : GCD(b, (a % b));
}
int main() {
	
	int M, N, ans;
	cin >> M >> N;
	ans = GCD(M, N);
	cout << ans << "\n";

	return 0;
}
