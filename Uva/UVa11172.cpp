#include <bits/stdc++.h>

using namespace std;

int main() {
    int t,i;

    cin >> t;
    long long num[t][2];

    for (i = 0; i < t; ++i)
        cin >> num[i][0] >> num[i][1];
    
    for (i = 0; i < t; ++i) {
        if (num[i][0] > num[i][1])
            cout << ">\n";
        else if (num[i][0] < num[i][1])
            cout << "<\n";
        else 
            cout << "=\n";
    }  
    return 0;
}