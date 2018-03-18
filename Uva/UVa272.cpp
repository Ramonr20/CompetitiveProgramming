#include <bits/stdc++.h>

using namespace std;

int main() {

    string s, aux, izq, der;
    char quote = '\"';
    int cont;
    bool flag = true;
    vector<string> ans;

    while (getline(cin,s)) {

        aux = s;
        cont = 0;

        for (int i = 0; i < s.length(); ++i)
            if (s[i] == quote)
                cont++;
        
        for (int i = 0; i < aux.length() + cont; ++i) {
            if (s[i] == quote) {
                izq = s.substr(0,i);
                der = s.substr(i+1,s.length() - 1);
                s = flag ? izq + "``" + der: izq + "''" + der;
                if (flag)
                    flag = false;
                else 
                    flag = true;
            }
        }
        ans.push_back(s);

    }

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << "\n";

    return 0;
}