#include <bits/stdc++.h>
#define MAXN 51

using namespace std;

int main() {

	int N, flag = true;
	int pal[MAXN];

	cin >> N;

	for (int i = 0; i < N; ++i) 
		cin >> pal[i];

	if(!pal[0] || !pal[N-1])
		cout << "NO\n";
	else {
		for (int i = 0; i < N; ++i) {
			if (!(pal[i] == pal[N - 1 - i])) {
				flag = false;
				break;
			}
		}
		cout << (flag ? "SI\n" : "NO\n"); 
	}

	return 0;
}
