#include <bits/stdc++.h>

using namespace std;

bool verificar(int v[], int j, int n) {
    for (int i = j; i < n; ++i)
        if (v[i] != 0)
            return false;
    return true;
}

int main() {

    int n, ans = 0, i, j;
    bool flag = false;

    cin >> n;
    int l[n];

    for (int i = 0; i < n; ++i)
        cin >> l[i];
    
    for (i = 0; i < n; ++i) {
        // cout << "i = " << i << " ";
       for (j = i; j < n; ++j) {
        //    cout << "j = " << j << " ";
           if (l[j] == 1) {
                ans++;
                // cout << "aqui 2" << " ";
                flag = true;
            if (j == n - 1) {
                i = j;
                break;
            }
           }else if (l[j] == 0 && flag) {
               if (verificar(l, j, n)) {
                    i = n - 1;
                    break;
                }
                if (j == n - 1 && l[j] == 0) {
                    i = j;
                    break;
                }else {        
                    // cout << "aqui" << " ";   
                    ans++;
                    flag = false;
                    i = j;
                    break;
                }
           }
       }
    //    cout << "ans = " << ans << "\n";
    }
    
    cout << ans << "\n";

    return 0;
}