#include <bits/stdc++.h>

using namespace std;

typedef pair<int, char> ic;

vector<ic> senate;
vector<string> ans;
vector<float> porcents;

int T, N, nc;
int p = 65, tP, contC;

int main() {

    cin >> T;
    
    while (T--) {

        cin >> N;
        while (N--) {
            cin >> nc;
            contC += nc;
            senate.push_back(ic(nc, p++));
        }

        for (int i = 0; i < senate.size(); ++i)
                porcents[i] = senate[i].first / contC;

        while (!senate.empty()) {

            for (int i = 0; i < senate.size(); ++i) 
                for (int j = 0; j < senate.size(); ++j) {
                    if()
                }
        }

    }

    //for (int i = 0; i < 5; ++i)
      //  cout << senate[i].first << senate[i].second << "\n";

    return 0;
}