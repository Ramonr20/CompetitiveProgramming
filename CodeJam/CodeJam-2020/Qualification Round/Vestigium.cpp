#include <iostream>
#include <vector>
#include <bitset>

#define MAXN 110
using namespace std;

bitset<MAXN> line;
int matrix [MAXN][MAXN];
int N, M, T;

int main() {

    cin >> T;
    int x = 1, i, j;

    while (T--) {
        int k = 0, r = 0, c = 0;
        cin >> N;

        for (i = 0; i < N; ++i) {
            int aux = 0;
            for (j = 0; j < N; ++j) {
                cin >> M;
                matrix[i][j] = M;

                if (line[M]) aux++;
                else line[M] = 1;

                if (i==j) k += M;
            }
            if (aux > 0) r++;
            line.reset();
        }
        
        for (i = 0; i < N; ++i) {
            int aux = 0;
            for (j = 0; j < N; ++j) {
                if (line[matrix[j][i]]) aux++;
                else line[matrix[j][i]] = 1;
            }
            if (aux > 0) c++;
            line.reset();
        }
        cout << "Case #" << x++ << ": "  << k << ' ' << r << ' '<< c << '\n';
    }

    return 0;
}