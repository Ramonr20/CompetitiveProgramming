#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, n, sum, num;
    vector<int> places;
    
    cin >> t;

    while (t--) {
        places.clear();
        sum = 0;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> num;
            places.push_back(num);
        }
        sort(places.begin(),places.end());
        for (int k = 0; k < n - 1; ++k) {
            sum += places[k+1] - places[k];
        } 
        cout << sum * 2 << "\n";
    }


    return 0;
}
