#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	ll a, b, k, t;

	cin >> t;

	while (t--) {
		cin >> a >> b >> k;

		
		if (k % 2 == 0) {
			ll s = (a * ( k / 2));
			ll r = (b * ( k / 2));
			ll ans = s - r;
			cout << ans << '\n';
		} else {
			ll s = (a * ceil((double)k / 2));
			ll r = (b * floor((double)k / 2));
			ll ans = s - r;
			cout << ans << '\n';
		}
	}
	return 0;
}
