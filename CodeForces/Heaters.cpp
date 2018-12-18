#include <bits/stdc++.h>
#include <bitset>

using namespace std;

vector<int> heatersOn(1002);
bitset<1002> warmup;

void fill(int init, int fin) {

	for (int i = init; i < fin; ++i)
		warmup[i] = true;

} 
int main() {

	int N, r, ans = true;
 	int l, ri, cont = 0;

	cin >> N >> r;

	for (int i = 0; i < N; ++i)
		cin >> heatersOn[i];
	
	for (int i = 0; i < N; ++i) {
		if (heatersOn[i] && (!warmup[i-1] or !warmup[i+1])) {
			l = i - r + 1;
			ri = i + r - 1;
			fill(l, ri);
			cont++;
		}			
	}
	for (int i = 0; i < N; ++i) {
		if (warmup[i] == false) {
			ans = false;
			break;
		}
	}	

	cout << (ans ? cont : -1) << '\n';

	return 0;
}
