#include <bits/stdc++.h>
#define MAXN 12
#define PB push_back

using namespace std;

typedef long double ld;
typedef vector<int> vi;

ld lamp[MAXN];
bool vis[MAXN];
int N, On;
ld D, L;
vi lOn;

int main() {

	cin >> N;
	cin >> D;

	for (int i = 0; i < N; ++i) {
		cin >> L;
		lamp[i] = L / 2;
	}

	for (int i = 0; i < N; ++i) cout << lamp[i] << ' ';
	cout << '\n';

	for (int i = 1; i < N; ++i) {
		if (lamp[i] < D && lamp[i-1] < D) {
			if ((lamp[i] + lamp[i+1]) >= D) {
				if (!vis[i]) vis[i] = 1, lOn.PB(i+1);
				if (!vis[i-1]) vis[i-1] = 1, lOn.PB(i);
			}
		} else if (lamp[i] >= D && lamp[i-1] < D) {
			if (!vis[i]) vis[i] = 1, lOn.PB(i+1);
		} else {
			if (!vis[i-1]) vis[i-1] = 1, lOn.PB(i);
		}
	}

	sort(lOn.begin(), lOn.end());

	cout << lOn.size() << '\n';
	for (int i = 0; i < lOn.size(); ++i) {
		cout << lOn[i] << ' ';
	}
	cout << '\n';
	for (int i = 0, j = 0; i < N; ++i) { 
		if ((lOn[j] - 1) == i) {
			j++;
			continue;	
		}
		else {
			cout << (i + 1) << ' ';
		}
	}
	cout << '\n';

	return 0;
}
