#include <iostream>
#include <vector>

using namespace std;

void boobleSort(vector<int> &v){

    int temp;
    
    for(int i = 0; i < v.size(); ++i){
        for(int j = i+1; j < v.size(); j++){
            if(v[i] > v[j]){
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

}
int main(){

    int N,a;

    cin >> N;
    vector<int> v(N);

    for(int i = 0; i < N; ++i){
        cin >>  v[i];   
    }

    boobleSort(v);

    for(int i = 0; i < N; ++i){
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}