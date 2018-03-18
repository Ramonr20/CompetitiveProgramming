#include <bits/stdc++.h>

using namespace std;

int N;

bool isEqual(vector<vector<int> > &v){

        for(int j = 1; j < N; ++j){
            if(v[0][0] == v[j][j])
                continue;
            else
            return false;
        }

    return true;
}

int main(){

    bool ans = false;

    cin >> N;
    
    vector<vector<int> > v(N,vector<int>(N));

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; j++){
            cin >> v[i][j];
        }
    }
    
    if(N != 0)
        ans = isEqual(v);

    if(ans)
        cout << "SI\n";
    else
        cout << "NO\n";

    return 0;
}