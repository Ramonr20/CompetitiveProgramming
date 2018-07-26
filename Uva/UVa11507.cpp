#include <bits/stdc++.h>

using namespace std;


int main() {

	int L;
	string mov, init = "+x", ans;
	int i = 0;
	bool flag, flag2;
	string arr[100001];

	while (scanf("%d", &L)) { 
		flag = flag2 = true;
		
		while (L--) {	
			cin >> mov;

			if (mov != "No" && flag) {
				init = mov;
				flag = false;
			}

			if (mov[1] != init[1])
				continue;
			else if (flag2) {
				if (mov[0] == init[0]) {
					ans = "-x";
					init = mov;
				}else {
					ans = "+x";
					init = mov;
				}
				flag2 = false;
			}else 
				ans = mov;
		}
	}
	return 0;
}



