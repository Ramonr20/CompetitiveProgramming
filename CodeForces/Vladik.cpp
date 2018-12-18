#include <bits/stdc++.h>

using namespace std;


int main() {

    int vl, va;
    int cant = 1;
    bool flag = true;

    cin >> vl >> va;

    while (true) {
        if (flag) {
            vl -= cant;
            cant++;
            flag = false;
        }else {
            va -= cant;
            cant++;
            flag = true;
        }
        if (vl < cant && flag) {
            cout << "Vladik" << "\n";
            break;
        }else if (va < cant && !flag) {
            cout << "Valera" << "\n";
            break;
        }
    }

    return 0;
}

