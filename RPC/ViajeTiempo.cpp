#include <bits/stdc++.h>

using namespace std;

char validar(int A, int B, int C) {

    if(A + B == C)
        return 'S';
    else if(A + C == B)
        return 'S';
    else if(B + C == A)
        return 'S';
    else if(A == B)
        return 'S';
    else if(A == C)
        return 'S';
    else if(B == C)
        return 'S';
    return 'N';
}

int main() {

    int A, B, C;
    char ANS;
    
    cin >> A >> B >> C;

    ANS = validar(A, B, C);

    cout << ANS << "\n";

    return 0;
}