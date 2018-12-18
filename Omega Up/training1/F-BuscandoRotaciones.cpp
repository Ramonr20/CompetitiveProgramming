#include <bits/stdc++.h>

using namespace std;

string A(""), B("");
std::bitset<1000> vis;

bool sameLetters() {

	bool flag = false;

	for (int i = 0; i < A.length(); ++i) {
		if (flag) return false;
		for (int j = 0; j < B.length(); ++j) {
			flag = true;
			if (A[i] == B[j] && !vis[j]) {
				vis[j] = true; 
				flag = false;
				break;
			}
		}
	}
	return true;
}
bool letters() {

	for (int i = 0; i < A.length(); ++i)
		if (A[i] == B[i]) return false;

	return true;
}
int main() {

	cin >> A;
	cin >> B;
	if (A.length() != B.length()) cout << "No rotacion\n";
	else {
		if (sameLetters()) {
			if (letters()) cout << "Rotacion\n";
			else cout << "No rotacion\n";

		} else cout << "No rotacion\n";
	} 
	
	return 0;
}
