#include <bits/stdc++.h>

using namespace std;
	
int main()
{
	string f1,f2;
	string ans;
	int n;
	cin >> f1;
	cin >> f2;
	cin >> n;
	if(n == 1)
	{
		cout << f1 << "\n";
	}else if(n == 2)
	{
		cout << f2 << "\n";
	}
	else
	for(int i = 2; i < n; i++)
	{
	ans = "";
	
	ans += f1;
	ans	+= f2;

	f1 = f2;
	f2 = ans;
	}
	cout << ans << "\n";

}