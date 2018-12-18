#include <bits/stdc++.h>
#define PB push_back
#define MAXN 52

using namespace std;

vector<long> numBits(MAXN), decNums(MAXN);
vector<string> stringNums;

int N, ans = 0;
string nums;

vector<string> split(const string &s, char delimiter) {
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);

	while (getline(tokenStream, token, delimiter)) {
		tokens.PB(token);
	}

	return tokens;
}

int main() {

	cin >> N;
	cin >> nums;
	
	stringNums = split(nums,',');


	for (int i = 0; i < N; ++i) {
		decNums[i] = atoi(stringNums[i].c_str());
	}	

	for (int i = 0; i < N; ++i) {
		numBits[i] = __builtin_popcount(decNums[i]);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if ( numBits[i] > numBits[j])
				ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}
