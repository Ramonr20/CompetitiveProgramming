#include <bits/stdc++.h>

using namespace std;


string P;
vector<char> robot;

void makeR() {
	
	for (int i = 0; i < P.length(); ++i) {
		robot.push_back(P[i]);
	}
}

int suma() {
	int c = 1, s = 0;
	for (int i = 0; i < robot.size(); ++i) {
		if (robot[i] == 'C')
			c *= 2;
		if (robot[i] == 'S')
			s += c;
	}
	return s;
}

int main() {

	int T, D;
	char aux;
	int ans = 0;
	int x = 1;
	bool flag;
	
	cin >> T;
	
	while (T--) {
		
		flag = true;
		ans = 0;
		cin >> D >> P;	
		makeR();
		for(int i = 0; i < robot.size(); ++i) {
			if (suma() <= D) {
				flag = false;
				break;
			}
			if (robot[i] == 'C' && robot[i + 1] == 'S') {
				aux = robot[i];
				robot[i] = robot[i + 1];
				robot[i + 1] = aux;
				ans++;
				i = 0;
			}
			cout << i << "\n";
		}
		if (flag) {
			cout << "Case #" << x++ << ": IMPOSSIBLE\n"; 
		}else
			cout << "Case #" << x++ << ": " << ans << "\n";
		robot.clear();
	}	

	return 0;
}

