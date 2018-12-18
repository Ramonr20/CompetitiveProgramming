#include <bits/stdc++.h>
#define MAXN 102

using namespace std;

bool flats[MAXN];
int n, ans = 0;

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> flats[i];
	}

	for (int i = 1; i < n; ++i) {
		if ( (flats[i-1] == 1 && flats[i+1] == 1) && flats[i] == 0) {
			if (flats[i+2] == 0) {
				ans++;
				i += 3;
			}
			else {
				ans++;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
