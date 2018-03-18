#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,cont = 1, aux = 0;
    string s;
    vector<int> distance, ans;

    while (scanf("%d", &n), n) {
        cont = 1;
        cin >> s;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'Z') {
                distance.push_back(0);
                break;
            }
            else if (s[i] == 'R' && s[i+1] != '\0') {
                for (int j = i + 1; j < s.length(); ++j)  {
                    if (s[j] == '.') {
                        cont++;
                    }else if (s[j] == 'D') {
                        distance.push_back(cont);
                        cont = 1;
                        break;
                    } else if (s[j] == 'R') {
                        cont = 1;
                        break;
                    }
                }
            }
            else if (s[i] == 'D' && s[i+1] != '\0') {
                for (int j = i + 1; j < s.length(); ++j)  {
                    if (s[j] == '.') {
                        cont++;
                    }else if (s[j] == 'R') {
                        distance.push_back(cont);
                        cont = 1;
                        break;
                    } else if (s[j] == 'D') {
                        cont = 1;
                        break;
                    }
                }
            }   
        }

        aux = distance[0];
        for (int i = 0; i < distance.size(); ++i) {
            if (distance[i] < aux)
                aux = distance[i];
        } 
        ans.push_back(aux);
        distance.clear();
    }       
    
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << "\n";

    return 0;
}