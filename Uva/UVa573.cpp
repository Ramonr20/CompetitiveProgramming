#include <bits/stdc++.h>

using namespace std;

int H, D, F;
int days;
double prc, U, t, b;
bool flag;

int calc() {
	days = 0;
	flag = true;
	prc = U * ((float)F / 100);
	t = U; b = t - D;
	days++;
	while (true) {
	
		if (t > H)
			break;
		if (b < 0){
			flag = false;
			break;
		}
		if (U > 0) {
			U -= prc;
		}
		t = U + b;
		b = t - D;
		days++;	
	}
	return days;
}
int main() {

	int ans;

	while (scanf("%d", &H), H) {
		scanf("%lf %d %d", &U, &D, &F);
		ans = calc();
		if (flag)
			printf("success on day %d\n",ans);
		else		
			printf("failure on day %d\n",ans);
	}

	return 0;
}
