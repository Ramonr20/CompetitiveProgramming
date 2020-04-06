#include <bits/stdc++.h>
#define MAXN 10002

using namespace std;

int DP[MAXN];
int N, tmp;

void sec() {

	tmp = 3;
	DP[0] = tmp;

	for (int i = 1; i < MAXN; ++i) {
		DP[i] = DP[i - 1] + tmp;
		tmp += 2;	
	}
}

int main() {

	sec();
	
	cin >> N;
	cout << DP[N - 1] << '\n';

	return 0;
}
