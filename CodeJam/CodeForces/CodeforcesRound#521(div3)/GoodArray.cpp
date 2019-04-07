#include <bits/stdc++.h>
#define MAXN 200002
#define PB push_back

using namespace std;

int n;
long long sum;

vector<long long>[MAXN];
vector<int> nice;


void suma() {

	for (int i = 0; i < n; ++i) {
		sum += arr[i];
	}

}

int main() {

	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}	

	sum = 0;
	suma();
	
	for (int i = 0; i < n; ++i) {
		
	}

	cout << nice.size() << '\n';
	for (int i = 0; i < nice.size(); ++i) cout << nice[i] << ' ';
	cout << '\n';
}
