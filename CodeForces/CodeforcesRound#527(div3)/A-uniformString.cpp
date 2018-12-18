#include <bits/stdc++.h>

using namespace std;

string chain("");
int n, k, T;
int cont;

void backtrack(int mm, int n, int l) {
    if (cont < mm && l != 1) {
        chain += (l - 1) + 'a';
        cont++;
        backtrack(mm, n, l);
    } else if (l == 1){
        for (int i = 0; i < n - (mm * (k-1)); ++i) {
            chain += (l - 1) + 'a';
        }
        return;
    } else {
        cont = 0;
        l--;
        backtrack(mm, n, l);
    }
}

int main() {

    cin >> T;
    while (T--) {
        cin >> n >> k;
        cont = 0;
        chain = "";
        backtrack(floor(n/k), n, k);
        cout << chain << '\n';
    }
    return 0;
}