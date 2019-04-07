#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;
    string s;

    cin >> N;

    while (N--) {
        cin >> s;
        if (s.length() == 5)
            cout << 3 << "\n";
        else if ((s.at(0) == 'o' && s.at(1) == 'n') || (s.at(0) == 'o' && s.at(2) == 'e') || (s.at(1) == 'n' && s.at(2) == 'e'))
            cout << 1 << "\n";
        else 
            cout << 2 << "\n";
    }
    
    return 0;
}