#include <iostream>

using namespace std;

int main() {

    int n, m, o, l, suma;
    int i,j,k;

    cin >> n >> m >> o;
    int A[n][m], B[m][o];
    int C[n][o];

    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            cin >> A[i][j];
        
    for (i = 0; i < m; ++i)
        for (j = 0; j < o; ++j)
            cin >> B[i][j];

    for (i = 0; i < o; ++i) {
        for (j = 0; j < n; ++j) {
            suma = 0;
            for (k = 0; k < m; ++k) {
                suma += A[j][k] * B[k][i];
            }
            C[j][i] = suma;
        }        
    }
    
    for (i = 0; i < n; ++i){
        for (j = 0; j < o; ++j){
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}