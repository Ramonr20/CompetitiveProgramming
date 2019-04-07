#include <bits/stdc++.h>

using namespace std;

int main() {

	int L;
	string J;
	string end;
	while ((cin >> L), L) {
		end = "+x";
		for (int i = 1; i < L; ++i) {
			cin >> J;
			if (J == "No")
				continue;
			if (J == "+z") {
				if (end == "+x") end = "+z";
				else if (end == "-x") end = "-z";
				else if (end == "+z") end = "-x";
				else if (end == "-z") end = "+x";
			} else if (J == "-z") {
				if (end == "+x") end = "-z";
				else if (end == "-x") end = "+z";
				else if (end == "+z") end = "+x";
				else if (end == "-z") end = "-x";

			} else if (J == "+y") {
				if (end == "+x") end = "+y";
				else if (end == "-x") end = "-y";
				else if (end == "+y") end = "-x";
				else if (end == "-y") end = "+x";

			} else if (J == "-y") {
				if (end == "+x") end = "-y";
				else if (end == "-x") end = "+y";
				else if (end == "+y") end = "+x";
				else if (end == "-y") end = "-x";
			}
		}
		cout << end << "\n";
	}
	return 0;
}



