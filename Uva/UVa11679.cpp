#include <bits/stdc++.h>

using namespace std;

int N, B;
vector<int> ans;

bool found() {
	for (int i = 0; i < N; ++i)
		if (ans[i] < 0)
			return false;
	return true;	
}
	
int main() {

	int r, k, d, c, v;

	while (scanf("%d %d", &B, &N), B && N) {
		k = 0;
		while(B--) { scanf("%d", &r); ans.push_back(r); }
		
		for (int i = 0;i < N; ++i){
			scanf("%d %d %d", &d, &c, &v); 
			ans[d - 1] -= v;
			ans[c - 1] += v;
		}
		
		if (found()) 
			printf("S\n");
		else 
			printf("N\n");

		ans.clear();
	}
		
	return 0;
}
