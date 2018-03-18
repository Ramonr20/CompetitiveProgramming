#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXN 200005

using namespace std;

typedef unsigned long long lli;

lli list[MAXN];

int main()
{
	int N,M,p,q;
	lli ans;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> list[i];
	}

	cin >> 	M;

	while (M--) {
		ans = 0;
		cin >> p;
		cin >> q;
		for(int i = p - 1 ; i < q ;i++)
		{
			ans += list[i];
		}
		cout << ans%(1000000000+7) << "\n";
	}

	return 0;
}

//Esta solución excede el limite de tiempo 