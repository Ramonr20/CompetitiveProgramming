#include <bits/stdc++.h>

using namespace std;

int main() {

    int T, a, b, c, i = 1;

    cin >> T;

    while (T--) {

        cin >> a >> b >> c;
        if (a > b && a < c)
            cout << "Case " << i << ": " << a << "\n";
        else if (a < b && a > c)
            cout << "Case " << i << ": " << a << "\n"; 
        else if (b > a && b < c)
            cout << "Case " << i << ": " << b << "\n";
        else if (b < a && b > c)
            cout << "Case " << i << ": " << b << "\n";
        else if (c > a && c < b)
            cout << "Case " << i << ": " << c << "\n";
        else if (c < a && c > b)
            cout << "Case " << i << ": " << c << "\n";
        ++i;
    }

    return 0;
}