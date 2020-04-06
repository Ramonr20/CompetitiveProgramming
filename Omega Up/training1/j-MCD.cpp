#include <bits/stdc++.h>
#include <bitset>
#define GCD(a, b) __gcd(a, b)
#define EB emplace_back
#define MAXN 200002

using namespace std;

bitset<200002> vis;

int NUMS[MAXN]; 
//vector<int> NUMS(200000,1000);

int N = 200000, countOnes = 0;

bool ones() {

	for (int i = countOnes; i < N; ++i) {
		if (NUMS[i] != 1) return 0;
		countOnes++;
	}
	return 1;
}

int main() {

	int flag = 1, ans = 0;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> NUMS[i];	
	}

	while (!ones()) {
		for (int i = 0; i < N; ++i) {
			if (i <= N - 2)
				NUMS[i] = GCD(NUMS[i], NUMS[i+1]);		
			else if (i == N - 1) 
				NUMS[i] = GCD(NUMS[i], NUMS[0]);
		}
		ans++;
	}
	cout << ans << '\n';

	return 0;
}
