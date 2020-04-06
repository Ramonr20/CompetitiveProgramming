#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int N, num, i = 1;
    int cont1, cont0;

    while (scanf("%d", &N), N) {
        cont1 = cont0 = 0;
        while(N--) {
            cin >> num;
            if (num == 0) 
                cont0++;
            else
                cont1++;
        }
        cout << "Case " << i++ << ": " << cont1 - cont0 << "\n";
    }
    
    return 0;
}