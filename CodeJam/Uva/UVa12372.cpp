#include <bits/stdc++.h>

using namespace std;

int main() {

    int T, L, W, H, i = 1;

    cin >> T;
    while (T--) {
        cin >> L >> W >> H;
        if(L > 20 || W > 20 || H > 20)
            cout << "Case " << i << ": bad\n";
        else 
            cout << "Case " << i << ": good\n";
        i++;
    }
    return 0;
}