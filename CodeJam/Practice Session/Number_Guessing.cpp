#include <bits/stdc++.h>


using namespace std;

typedef unsigned long long int ulli;

int T, N;
ulli A, B;

ulli floo() {
	ulli m = floor((A + B) / 2);
	return m;
}

int main() {
	
	ulli ans;
	string res("");
	cin >> T;
	while (T--) {
				
		cin >> A >> B;
		cin >> N;
		while (N--) {
		
			ans = floo();
			cout << ans << "\n";
			cin >> res;
			if (res == "TOO_SMALL") {
				A = ans + 1;
			}else if (res == "TOO_BIG") {
				B = ans;
			} else {
				break;
			}
		}		
	}

	return 0;
}
