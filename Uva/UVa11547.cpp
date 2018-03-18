#include <bits/stdc++.h>


using namespace std;

int main() {

    int T, N, res, ans;
    int tens;
    cin >> T;

    while (T--) {
        tens = 2;
        cin >> N;
        res = ((((( N * 567 ) / 9 ) + 7492) * 235)/47) - 498;
        while(tens--) {
            ans = res % 10;
            res /= 10;
        }
        cout << abs(ans) << "\n";
    }

    return 0;
}